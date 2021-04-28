/*
*   Author: Max Franz
*   Date: 10/27/20
*/

#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//This is the weak collision testing function
void weak() {
	//Most of the variables are initialized here
     	EVP_MD_CTX *mdctx;
     	const EVP_MD *md;
     	unsigned char md_value[EVP_MAX_MD_SIZE];
     	unsigned int md_len;
	bool found = false;
	char givenPlainText[] = "I like to draw a lot.";
	int plainTextLen = strlen(givenPlainText);
	int currTrials = 0, totalTrials = 0, avgTrials = 0;

	//This is the digestion of the given message
     	md = EVP_sha1();
     	mdctx = EVP_MD_CTX_create();
     	EVP_DigestInit_ex(mdctx, md, NULL);
     	EVP_DigestUpdate(mdctx, givenPlainText, plainTextLen);
     	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
     	EVP_MD_CTX_destroy(mdctx);

	char *givenCipherLong = malloc(md_len*2+1);
	memset(givenCipherLong, 0, md_len*2+1);

	//This converts the digested string into hex
     	for (int i = 0; i < md_len; i++) {
		char temp[5];
        	sprintf(temp, "%02x", md_value[i]);
		strcat(givenCipherLong, temp);
	}

	//This grabs the first 3 chars of the hex value
	char givenCipherShort[20];
	strncat(givenCipherShort, givenCipherLong, 3);


	printf("%s\n", ((int)givenCipherShort)%5);

	printf("Beginning Weak Collision Test...\n");

	//Seeding random with time
	srand(time(NULL));

	//This for loop runs 100 times to simulate 100 trials
	for(int x = 0; x < 100; x++) {
		found = false;
		currTrials = 0;
		//Each trial will run until a match is found, when a match is found, the while loop exits and restarts
		while(!found) {
			//These variables are only used for the random string, so they remain inside the while loop
			EVP_MD_CTX *mdctxRan;
			const EVP_MD *mdRan;
			unsigned char mdRan_value[EVP_MAX_MD_SIZE];
			unsigned int mdRan_len;
			char randString[21];

			//The setup for digesting the random string
			mdRan = EVP_sha1();
			mdctxRan = EVP_MD_CTX_create();
			EVP_DigestInit_ex(mdctxRan, mdRan, NULL);

			//An alphabet used to create the random string
			static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_";

			//This for loop will create a random string that is 21 chars long
			for(int i = 0; i < 21; ++i) {
				randString[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
			}

			randString[21] = 0;
			int randStringLen = strlen(randString);

			//The digestion is completed here
			EVP_DigestUpdate(mdctxRan, randString, randStringLen);
			EVP_DigestFinal_ex(mdctxRan, mdRan_value, &mdRan_len);
			EVP_MD_CTX_destroy(mdctxRan);

			char *randCipherLong = malloc(mdRan_len*2+1);
			memset(randCipherLong, 0, mdRan_len*2+1);

			//The digested message is being converted to hex
			for(int i = 0; i < mdRan_len; i++) {
				char temp[5];
				sprintf(temp, "%02x", mdRan_value[i]);
				strcat(randCipherLong, temp);
			}

			//The first 3 chars are grabbed in order to compare to the first 3 chars of the given cipher
			char randCipherShort[20];
			strncat(randCipherShort, randCipherLong, 3);

			//This if statement will check if a match is found.
			//If a match is found, the found boolean will become true and the current trial will end
			//If a match isn't found, the while loop will continue with random strings
			if(strcmp(givenCipherShort, randCipherShort) == 0) {
				currTrials++;
				found = true;
			} else {
				currTrials++;
			}

			//The strings are emptied and freed here
			strcpy(randCipherShort, "");
			free(randCipherLong);
		}

		//The total number of trials is recorded here
		totalTrials += currTrials;
	}

	printf("Finished Weak Collision Test!\n");

	//The average number of trials is calculated and printed here
	avgTrials = totalTrials / 100;
	printf("Weak Collision Average Trials: %d\n", avgTrials);

	free(givenCipherLong);
}

//This is the strong collision testing function
void strong() {
	//The hash array is initialized, hashArrayLen is also initialized to mkae it easier to keep track of
	char hashArray[1000][10];
	int hashArrayLen = 0;
	bool found = false, match = false;
        int currTrials = 0, totalTrials = 0, avgTrials = 0;

	printf("Beginning Strong Collision Test...\n");

	//Random is seeded with time
	srand(time(NULL));

	for(int x = 0; x < 100; x++) {
		//These variables are reset everytime a match is found
		found = false;
		currTrials = 0;
		hashArrayLen = 0;
		while(!found) {
			//Setting up the digest context
			EVP_MD_CTX *mdctx;
			const EVP_MD *md;
			unsigned char md_value[EVP_MAX_MD_SIZE];
			unsigned int md_len;
			char randString[21];

     			md = EVP_sha1();
     			mdctx = EVP_MD_CTX_create();

     			EVP_DigestInit_ex(mdctx, md, NULL);

			//An alphabet used to create the random string
                        static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_";

                        //This for loop will create a random string that is 21 chars long
                        for(int i = 0; i < 21; ++i) {
                                randString[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
                        }

                        randString[21] = 0;
                        int randStringLen = strlen(randString);

			//This is where the digestion is completed
     			EVP_DigestUpdate(mdctx, randString, randStringLen);
     			EVP_DigestFinal_ex(mdctx, md_value, &md_len);
     			EVP_MD_CTX_destroy(mdctx);

                        char *randCipherLong = malloc(md_len*2+1);
                        memset(randCipherLong, 0, md_len*2+1);

                        //The digested message is being converted to hex
                        for(int i = 0; i <md_len; i++) {
                                char temp[5];
                                sprintf(temp, "%02x", md_value[i]);
                                strcat(randCipherLong, temp);
                        }

                        //The first 3 chars are grabbed in order to compare to the first 3 chars of the given cipher
                        char randCipherShort[20];
                        strncat(randCipherShort, randCipherLong, 3);

			//Match gets reset to false for every single trial
			match = false;
			//If this is the first hash created, then it is placed into the first array slot
			if(hashArrayLen == 0) {
				strcpy(hashArray[0], randCipherShort);
				hashArrayLen++;
				currTrials++;
			} else { //If it is not the first hash created, more things happen
				for(int i = 0; i < hashArrayLen; i++) { //The hashArray is cycled through and every value in the array is compared to the current hash
					if(strcmp(randCipherShort, hashArray[i]) == 0) { //If they match, the current trial will exit, found and match are set to true
						found = true;
						match = true;
					}
				} //If no match is found, the hash is added to the array, hashArrayLen increases, and the trials continue
				if(match == false) {
					strcpy(hashArray[hashArrayLen], randCipherShort);
					hashArrayLen++;
				}
				currTrials++;
			}
                        //The cipher strings are emptied and freed here
                        strcpy(randCipherShort, "");
                        free(randCipherLong);
		}
		totalTrials += currTrials;
	}
        printf("Finished Strong Collision Test!\n");

        //The average number of trials is calculated and printed here
        avgTrials = totalTrials / 100;
        printf("Strong Collision Average Trials: %d\n", avgTrials);
}

//This is the main function, it calls the functions that test both weak and strong collision
int main() {
	//This function call will start the weak collision test
	weak();

	printf("\n");

	//This function call will start the strong collision test
	strong();

	return 0;
}
