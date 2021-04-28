/*
*   Written by Max Franz, 10/20/20
*   This program will let you choose either the largest file, smallest file, or your choice of file to sort the movies into separate .txt files based on year.
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define PREFIX "movies_"
#define SUFFIX ".csv"

/* Struct for movie information */
//I reused this struct from Assignment 1
struct movie {
    char *title;
    int year;
    char *languages;
    double rating;
    struct movie *next;
};

/* Parse the current line which is space delimited and create a
*  movie struct with the data in this line.
*
*  I reused this code from Assignment 1
*/
struct movie *createMovie(char *currLine) {
    struct movie *currMovie = malloc(sizeof(struct movie));

    // For use with strtok_r
    char *saveptr;

    // The first token is the title
    char *token = strtok_r(currLine, ",", &saveptr);
    currMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->title, token);

    // The next token is the year
    token = strtok_r(NULL, ",", &saveptr);
    currMovie->year = atoi(token);

    // The next token is the languages
    token = strtok_r(NULL, ",", &saveptr);
    currMovie->languages = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->languages, token);

    // The last token is the rating
    token = strtok_r(NULL, "\n", &saveptr);
    currMovie->rating = strtod(token, NULL);

    // Set the next node to NULL in the newly created movie entry
    currMovie->next = NULL;

    return currMovie;
}

/*
* Return a linked list of movies by parsing data from
* each line of the specified file.
*
* I reused this code from Assignment 1
*/
struct movie *processFile(char *filePath) {
    // Open the specified file for reading only
    FILE *movieFile = fopen(filePath, "r");

    char *currLine = NULL;
    size_t len = 0;
    ssize_t nread;
    char temp[40];
    int movieCount = 0;

    // The head of the linked list
    struct movie *head = NULL;
    // The tail of the linked list
    struct movie *tail = NULL;

    fgets(temp, 60, movieFile);
    // Read the file line by line
    while ((nread = getline(&currLine, &len, movieFile)) != -1)
    {
        // Get a new movie node corresponding to the current line
        struct movie *newNode = createMovie(currLine);

        // Is this the first node in the linked list?
        if (head == NULL)
        {
            // This is the first node in the linked link
            // Set the head and the tail to this node
            head = newNode;
            tail = newNode;
        }
        else
        {
            // This is not the first node.
            // Add this node to the list and advance the tail
            tail->next = newNode;
            tail = newNode;
        }
    movieCount++;
    }

    free(currLine);
    fclose(movieFile);

    return head;
}

/*
*   This function will fill the newly created directory with the correct name and number of .txt files.
*   Those .txt files will then be filled with the appropriate movies.
*/
void dirFiller(struct movie *list, char newDir[40]) {
	int movieCount = 0;
	struct movie *curr = list;

    	//This loop will find out the movieCount. I reused this code from Assignment 1.
    	while(curr != NULL) {
        	movieCount++;
        	curr = curr->next;
    	}

    	int movieYears[movieCount];
    	curr = list;

    	//Every year attached to every movie is recorded here I reused this code from Assignment 1.
    	for(int x = 0; x < movieCount; x++) {
    	    	movieYears[x] = curr->year;
        	curr = curr->next;
    	}

    	//Every duplicate year is deleted here so that we're left with an array that has one of every year present in the .CSV. I reused this code from Assignment 1.
    	int arraySize = movieCount;
    	for(int x = 0; x < arraySize; x++) {
        	for(int y = x + 1; y < arraySize; y++) {
            		if(movieYears[x] == movieYears[y]) {
                		for(int z = y; z < arraySize; z++) {
                    			movieYears[z] = movieYears[z + 1];
                		}
                		arraySize--;
                		y--;
            		}
       	 	}
    	}

	curr = list;

	//This while loop will loop through every movie in the linked list of movies
	while(curr != NULL) {
		//A filePath is created for the movie currently being dealt with
		char filePath[40];
		sprintf(filePath, "./%s/%d.txt", newDir, curr->year);

		int fileDescriptor;

		//This line determines if the year.txt file already exists, if it does then the current movie will be appended to the end,
		//if the year.txt file doesn't exist a new one will be created with the correct permissions and the current movie will be the first entry.
		fileDescriptor = open(filePath, O_RDWR | O_CREAT | O_APPEND, 0640);

		write(fileDescriptor, curr->title, strlen(curr->title));
		write(fileDescriptor, "\n", strlen("\n"));

		//File is closed
		close(fileDescriptor);

		//Next movie is selected
		curr = curr->next;
	}
}

/*
*   This function creates the new directory with the correct name.
*/

void dirMaker(struct movie *list) {
	//Random is seeded with time here.
	srand(time(NULL));
	char onid[10] = "franzmax";
	long int rNum = random() % 100000;
	char dirName[30];
	sprintf(dirName, "franzmax.movies.%ld", rNum);
	//A new directory is created here, I assume because the number is random that there will be no duplicates.
	mkdir(dirName, 0750);


	//The following code is from the repl.it example located here: https://repl.it/@cs344/35statexamplec; it has not been modified here
	//This code is being used to get the name of the directory that was just created, there's probably a better way to do this, but I couldn't figure out how
	DIR* currDir = opendir(".");
  	struct dirent *aDir;
  	time_t lastModifTime;
  	struct stat dirStat;
  	int i = 0;
  	char newDir[40];

  	// Go through all the files and directories in the current directory.
  	while((aDir = readdir(currDir)) != NULL){

    		if(strncmp(onid, aDir->d_name, strlen(onid)) == 0){
      			// Get meta-data for the current entry
      			stat(aDir->d_name, &dirStat);

      			// Use the difftime function to get the time difference between the current value of lastModifTime and the st_mtime value of the directory entry
      			if(i == 0 || difftime(dirStat.st_mtime, lastModifTime) > 0){
          			lastModifTime = dirStat.st_mtime;
          			memset(newDir, '\0', sizeof(newDir));
          			strcpy(newDir, aDir->d_name);
        		}
      			i++;
    		}
  	}
  	// Close the directory
  	closedir(currDir);

	printf("Created directory with name %s\n", newDir);
	printf("\n");

	dirFiller(list, newDir);
}

/*
*   This function will find the largest file with the correct prefix and file extension.
*/

void largeFile() {

	//The following code is from the repl.it example located here: https://repl.it/@cs344/35statexamplec; it has been modified here to find the largest file
	DIR* currDir = opendir(".");
	struct dirent *aDir;
	off_t fSize;
	struct stat dirStat;
	char fileName[60];
	size_t fileNameLen;
	size_t extLen = strlen(SUFFIX);
	int i = 0;

	// Go through all the files and directories in the current directory.
	while((aDir = readdir(currDir)) != NULL){
		fileNameLen = strlen(aDir->d_name);

		//This if statement has been modified to also look for the correct file extension
		if((strncmp(PREFIX, aDir->d_name, strlen(PREFIX)) == 0) && ((strcmp(&aDir->d_name[fileNameLen-extLen], SUFFIX)) == 0)) {
			// Get meta-data for the current entry
			stat(aDir->d_name, &dirStat);

			//This if statement finds the largest file and records it
        		if(i == 0 || (dirStat.st_size > fSize)){
                		fSize = dirStat.st_size;
          			memset(fileName, '\0', sizeof(fileName));
          			strcpy(fileName, aDir->d_name);
                	}
			i++;
    		}
  	}

	printf("Now processing the chosen file named %s\n", fileName);
	printf("\n");
	struct movie *list = processFile(fileName);

  	// Close the directory
  	closedir(currDir);

	dirMaker(list);
}

/*
*   This function will find the smallest file with the correct prefix and file extension.
*/

void smallFile() {

	//The following code is from the repl.it example located here: https://repl.it/@cs344/35statexamplec; it has been modified here to find the smallest file
	DIR* currDir = opendir(".");
	struct dirent *aDir;
	off_t fSize;
	struct stat dirStat;
	char fileName[60];
	size_t fileNameLen;
	size_t extLen = strlen(SUFFIX);
	int i = 0;

	// Go through all the files and directories in the current directory.
	while((aDir = readdir(currDir)) != NULL){
		fileNameLen = strlen(aDir->d_name);

		//This if statement has been modified to also look for the correct file extension
		if((strncmp(PREFIX, aDir->d_name, strlen(PREFIX)) == 0) && ((strcmp(&aDir->d_name[fileNameLen-extLen], SUFFIX)) == 0)) {
			// Get meta-data for the current entry
			stat(aDir->d_name, &dirStat);

			//This if statement finds the smallest file and records it
        		if(i == 0 || (fSize > dirStat.st_size)){
                		fSize = dirStat.st_size;
          			memset(fileName, '\0', sizeof(fileName));
          			strcpy(fileName, aDir->d_name);
                	}
			i++;
    		}
  	}

	printf("Now processing the chosen file named %s\n", fileName);
	printf("\n");
	struct movie *list = processFile(fileName);

  	// Close the directory
  	closedir(currDir);

	dirMaker(list);
}

/*
*   This function will process the file that the user specifies.
*/

void customFile() {
	char fileName[60];
	int count = 0;
	printf("Enter the complete filename: ");
	scanf("%s", fileName);
	printf("\n");

	DIR* currDir = opendir(".");
	struct dirent *aDir;

	//This while loop checks the current cirectory to see if the file the user entered actually exists.
	while((aDir = readdir(currDir)) != NULL) {
		if(!strcmp(aDir->d_name, fileName)) {
			//Count will increase if the file exists
			count++;
		}
	}

	closedir(currDir);

	//If count is greater than 0, then the file does exist
	if(count > 0) {
		printf("Now processing the chosen file named %s\n", fileName);
		printf("\n");
		struct movie *list = processFile(fileName);
		dirMaker(list);
	//If count hasn't changed then the file doesn't exist
	} else {
		printf("The file %s was not found, try again.\n", fileName);
		printf("\n");
		customFile();
	}

}

/*
*   This function will let the user choose how they will process a file, either the largest, smallest, or a specific file
*/

void fileChoice() {
	int secondChoice = 0;
	printf("Enter 1 to pick the largest file.\n");
	printf("Enter 2 to pick the smallest file.\n");
	printf("Enter 3 to specify the name of a file.\n");
	printf("\n");
	printf("Enter 1, 2, or 3: ");
	scanf("%d", &secondChoice);
	printf("\n");

	if(secondChoice == 1) {
		largeFile();
	} else if(secondChoice == 2) {
		smallFile();
	} else if(secondChoice == 3) {
		customFile();
	} else {
		printf("You must choose 1, 2, or 3!\n");
		fileChoice();
	}
}

/*
*   This function will let the user choose if they want to process a file or exit the program
*/

void processOrExit() {
	int firstChoice = 0;
	printf("1. Select file to process\n");
	printf("2. Exit program\n");
	printf("\n");
	printf("Enter 1 or 2: ");
	scanf("%d", &firstChoice);
	printf("\n");

	if(firstChoice == 1) {
		fileChoice();
		processOrExit();
	} else if(firstChoice == 2) {
		exit(0);
	} else {
		printf("You must choose 1 or 2!\n");
		processOrExit();
	}
	printf("\n");
}

/*
*   This is the main function and calls processOrExit() for the first time,
*   starting the program that only the user can exit out of.
*/

int main(void) {
	processOrExit();

	return 0;
}
