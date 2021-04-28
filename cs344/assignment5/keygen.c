#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));

	if(argc < 2) {
		fprintf(stderr, "%s\n", "Not enough commandline arguments!");
		exit(0);
	} else {
		char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
		int len = atoi(argv[1]);
		char key[len];
		strcpy(key, "");

		for(int i = 0; i < len; i++) {
			char temp = alphabet[rand()%27];
			strncat(key, &temp, 1);
		}

		//key[len] = '\n';
		fprintf(stdout, "%s\n", key);
	}

	return 0;
}
