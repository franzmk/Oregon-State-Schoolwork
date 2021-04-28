/*
**  Max Franz
**  11/18/20
**  Multi-threaded Producer Consumer Pipeline
** **WARNING: THIS PROGRAM DOESN'T WORK AT ALL**
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void *getInput(void*);
void *replaceNewLines(void*);
void *replacePlusSigns(void*);
void *outputText(void*);

//Buffer 1 Setup
char *buff1;
int count_1 = 0;
pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full_1 = PTHREAD_COND_INITIALIZER;

//Buffer 2 Setup
char *buff2;
int count_2 = 0;
pthread_mutex_t mutex_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full_2 = PTHREAD_COND_INITIALIZER;

//Buffer 3 Setup
char *buff3;
int count_3 = 0;
pthread_mutex_t mutex_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full_3 = PTHREAD_COND_INITIALIZER;

//This is the total length of the input
int totalLen;

//This function places the input array on the first buffer that is shared between getInput and replaceNewLines
void putBuff1(char *inputArray) {
	pthread_mutex_lock(&mutex_1); //The mutex is locked

	buff1 = inputArray; //The data is saved
	//printf("%s\n", buff1);
	count_1++; //Increase count

	pthread_cond_signal(&full_1); //Full signal is sent
	pthread_mutex_unlock(&mutex_1); //The mutex is unlocked
}

//This function gets input from stdin
void *getInput(void *args) {
	char inputArray[50000]; //Char array is initialized
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, stdin)) != -1) { //Getline will read in all input from stdin
		strcat(inputArray, line);
		totalLen = totalLen + (int)read;
	}

	putBuff1(inputArray); //The array is put on the 1st buffer
}

//This function returns the first buffer
char* getBuff1() {
	pthread_mutex_lock(&mutex_1); //The mutex is locked

	while(count_1 == 0) { //If there is nothing in the buffer, the thread waits
		pthread_cond_wait(&full_1, &mutex_1);
	}

	count_1--; //Count is decreased
	printf("%s\n", buff1);
	pthread_mutex_unlock(&mutex_1); //The mutex is unlocked

	return buff1; //The array is returned
}

//This function puts that input array on the second buffer after the newlines have been replaced with spaces
void putBuff2(char *inputArray) {
	pthread_mutex_lock(&mutex_2); //The mutex is locked

	buff2 = inputArray; //The data is saved
	printf("%s\n", buff2);
	printf("\n");
	count_2++; //Count is increased

	pthread_cond_signal(&full_2); //The full signal is sent
	pthread_mutex_unlock(&mutex_2); //The mutex is unlocked
}

//This function replaces all newline characters with spaces
void *replaceNewLines(void *args) {
	char *inputArray = getBuff1(); //The input array is retrieved
	printf("%s\n", inputArray);
	for(int i = 0; i < 50000; i++) { //The for loop cycles through every character and changes them where necessary
		if(inputArray[i] == '\n') {
			inputArray[i] = ' ';
		}
	}
	printf("newline\n");
	printf("%s\n", inputArray);
	putBuff2(inputArray); //The input array is placed on the second buffer
}

//This function returns the second buffer
char* getBuff2() {
	pthread_mutex_lock(&mutex_2); //The mutex is locked

	while(count_2 == 0) { //If there is nothing in the buffer, the thread waits
		pthread_cond_wait(&full_2, &mutex_2);
	}

	char *temp = buff2; //The data is saved

	count_2--; //Count is decreased

	pthread_mutex_unlock(&mutex_2); //The mutex is unlocked

	return temp; //The data is returned
}


//The function saves the input array to the third buffer after the plusses have been replaced with ^
void putBuff3(char *inputArray) {
	pthread_mutex_lock(&mutex_3); //The mutex is locked

	buff3 = inputArray; //The data is saved

	count_3++; //Count is increased

	pthread_cond_signal(&full_3); //The full signal is sent
	pthread_mutex_unlock(&mutex_3); //The mutex is unlocked
}


//This function replaces ++ with ^
void *replacePlusSigns(void *args) {
	char *inputArray = getBuff2(); //The input array is retrieved
	printf("\n");
	printf("%s\n", inputArray);
	for(int i = 0; i < totalLen; i++) { //This for loop cycles through all characters
		if((inputArray[i] == '+') && (inputArray[i + 1] == '+')) { //If two + are found in a row, there replaced with one ^
			inputArray[i] = '^';
			inputArray[i + 1] = '-'; //This extra character is ussed so that the program knows to remove it because we don't want an extra space between the ^ and the next character
		}
	}

	char *src, *dst;
	for(src = dst = inputArray; *src != '\0'; src++) { //This function was found here: https://stackoverflow.com/questions/5457608/how-to-remove-the-character-at-a-given-index-from-a-string-in-c
		*dst = *src;
		if(*dst != '-') {
			dst++;
		}
	}
	*dst = '\0';
	printf("after replace\n");
	printf("%s\n", inputArray);
	//printf("\n");
	putBuff3(inputArray); //The input array is sent the third buffer
}


//This function retrieves the third buffer
char* getBuff3() {
	pthread_mutex_lock(&mutex_3); //The mutex is locked

	while(count_3 == 0) { //If the buffer is empty, the thread waits
		pthread_cond_wait(&full_3, &mutex_3);
	}

	char *temp = buff3; //The data is saved

	count_3--; //Count is decreased

	pthread_mutex_unlock(&mutex_3); //the mutex is unlocked

	return temp; //The data is returned
}


//This function will output the text
void *outputText(void *args) {
	char *inputArray = getBuff3(); //The third buffer is retrieved
	//printf("%s\n", inputArray);
	for(int i = 0; i < 80; i++) { //The for loop runs 80 times so that 80 characters are printed at once
		if((inputArray[i] == 'S') && (inputArray[i + 1] == 'T') && (inputArray[i + 2] == 'O') && (inputArray[i + 3] == 'P')) { //If STOP is found, the printing stops
			//exit(0);
			break;
		} else {
			printf("%c", inputArray[i]); //Each character is printed one at a time
		}
	}
	//printf("\n");
	fflush(stdout);
}

//This is the main function, the htreads are created and ran from here
int main() {
	pthread_t input_t, newline_t, plus_t, output_t; //The threads are intialized here

	pthread_create(&input_t, NULL, getInput, NULL); //This is the input thread
	pthread_create(&newline_t, NULL, replaceNewLines, NULL); //This is the newline replacement thread
	pthread_create(&plus_t, NULL, replacePlusSigns, NULL); //This is the plus sign replacement thread
	pthread_create(&output_t, NULL, outputText, NULL); //This is the output thread

	pthread_join(input_t, NULL);
	pthread_join(newline_t, NULL);
	pthread_join(plus_t, NULL);
	pthread_join(output_t, NULL);

	return EXIT_SUCCESS; //When all threads are done, exit successfully
}
