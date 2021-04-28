#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct for movie information */
struct movie {
    char *title;
    int year;
    char *languages;
    double rating;
    struct movie *next;
};

/* Parse the current line which is space delimited and create a
*  movie struct with the data in this line
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
*/
struct movie *processFile(char *filePath) {
    // Open the specified file for reading only
    FILE *movieFile = fopen(filePath, "r");

    char *currLine = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;
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
        // Get a new student node corresponding to the current line
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

    printf("Processed %s and parsed data for %d movies\n", filePath, movieCount);
    printf("\n");
    return head;
}

/*
*   This function will ask the user for a specific year to sort the movies by.
*   If the year doesn't exist, a message will say so. If movies from that year do
*   exist, they'll be printed to the screen
*/

void specYear(struct movie *list) {
    int uYear;
    int count = 0;

    printf("Enter the year for which you want to see movies: ");
    scanf("%d", &uYear);
    printf("\n");

    //This is where the printing takes place, if the years match up then the corresponding move title is printed.
    while(list != NULL) {
        if(uYear == list->year) {
            printf("%s", list->title);
            printf("\n");
            list = list->next;
            count++;
        } else {
            list = list->next;
        }
    }

    //If no movie is found, this is printed.
    if(count == 0) {
        printf("No data about movies released in the year %d.", uYear);
        printf("\n");
    }
    printf("\n");
}

/*
*   This function will print the highest rated movies from each year. This was
*   quite difficult to code and is the reason why my assignment is late.
*/

void highRate(struct movie *list) {
    int movieCount = 0;
    struct movie *curr = list;

    //This loop will find out the movieCount.
    while(curr != NULL) {
        movieCount++;
        curr = curr->next;
    }

    int movieYears[movieCount];
    curr = list;

    //Every year attached to every movie is recorded here
    for(int x = 0; x < movieCount; x++) {
        movieYears[x] = curr->year;
        curr = curr->next;
    }

    //Every duplicate year is deleted here so that we're left with an array that has one of every year present in the .CSV
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

    //This is where the highest rated movie is calculated. I go through each individual year and compare every movie against it.
    //If the year matches, I go and compare the rating of that movie with the rating in the current slot. If the rating is larger,
    //then the current movie replaces the movie that was already in the array. I broke up the three printed parts for this function into
    //three seperate arrays because that was easier for me to deal with as well.
    curr = list;
    double movieRates[arraySize];
    char *movieNames[arraySize];
    for(int x = 0; x < arraySize; x++) {
        for(int y = 0; y < movieCount; y++) {
            if(movieYears[x] == curr->year) {
                if(curr->rating > movieRates[x]) {
                    movieRates[x] = curr->rating;
                    movieNames[x] = curr->title;
                }
            }
            curr = curr->next;
        }
        curr = list;
    }

    //After the highest ratings for every year are found, they get printed
    for(int x = 0; x < arraySize; x++) {
        printf("%d %g %s\n", movieYears[x], movieRates[x], movieNames[x]);
    }
    printf("\n");
}

/*
*   This function will print any movies that were shown in the requested language. If a movie with that language
*   isn't being shwon, a message will say so.
*/

void specLang(struct movie *list) {
    char uLang[20];
    int count = 0;

    printf("Enter the language for which you want to see movies: ");
    scanf("%s", uLang);
    printf("\n");

    //If the requested language matches one of the movies, then that movie and it's corresponding year will be printed.
    while(list != NULL) {
        if(strcasestr(list->languages, uLang) != NULL) {
            printf("%d %s", list->year, list->title);
            printf("\n");
            list = list->next;
            count++;
        } else {
            list = list->next;
        }
    }

    //If a movie doesn't exist, this message will be printed
    if(count == 0) {
        printf("No data about movies in %s.", uLang);
        printf("\n");
    }
    printf("\n");
}

/*
*   This function allows the user to choose one of the four interactive options of the program.
*/

void funcOptions(struct movie *list) {
    int funcChoice = 0;

    printf("1. Show movies released in the specified year\n");
    printf("2. Show highest rated movie for each year\n");
    printf("3. Show the title and year of release of all movies in a specific language\n");
    printf("4. Exit the program\n");
    printf("\n");
    printf("Enter a choice from 1 - 4: ");
    scanf("%d", &funcChoice);
    printf("\n");

    //Depending on the value, one of these if options will be selected
    if(funcChoice == 1) {
        specYear(list);
        funcOptions(list);
    } if(funcChoice == 2) {
        highRate(list);
        funcOptions(list);
    } if(funcChoice == 3) {
        specLang(list);
        funcOptions(list);
    } if(funcChoice == 4) {
        exit(0);
    } else {
        printf("You must choose between 1 - 4!\n");
        printf("\n");
        funcOptions(list);
    }
}

/*
*   The main function of the program. This takes the command line argument and calls
*   for the file to be processed. Then it calls funcOptions() which lets the user 
*   choose out of the four interactive choices.
*/

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        printf("You must provide the name of the file to process\n");
        printf("Example usage: ./movies movies.csv\n");
        return EXIT_FAILURE;
    }

    struct movie *list = processFile(argv[1]);

    funcOptions(list);

    return EXIT_SUCCESS;
}
