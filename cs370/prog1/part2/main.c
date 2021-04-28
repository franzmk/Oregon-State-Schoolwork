/*
*   Author: Max Franz
*   Date: 10/27/20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/evp.h>

int main() {
	//All these variables are used at some point, I probably don't need all of them but this is what ended up happening.
	unsigned char outbuf[1024 + EVP_MAX_BLOCK_LENGTH];
	char hexedOutbuf[1024 + EVP_MAX_BLOCK_LENGTH];
	int outlen;
	unsigned char *plainText = "This is a top secret.";
	int plainTextLen = strlen(plainText);
	unsigned char *cipherText = "8d20e5056a8d24d0462ce74e4904c1b513e10d1df4a2ef2ad4540fae1ca0aaf9";
	int cipherTextLen = strlen(cipherText);
	unsigned char iv[16] = {0};
	char currentWord[50];
	char space = ' ';
	bool found = false;

	//Open the wordlist and confirm that it's opened correctly.
	FILE *wordList = fopen("./words.txt", "r");
	if(wordList == NULL) {
		printf("The word list file didn't open properly, exiting...\n");
		exit(1);
	}

	//This loop runs until the key is found or it will quit if no key is found
	while(!found) {
		//Creating a new cipher context
		EVP_CIPHER_CTX *ctx;
		ctx = EVP_CIPHER_CTX_new();

		//For my program, I opted to encrypt the plain text message everytime using a new key until the correct key is found
		//This function will get the current word to be used as a key
		fscanf(wordList, "%s", currentWord);

		//This code will ensure that the key is of length 16, if it isn't, spaces will be appended to the end
		if(strlen(currentWord) < 16) {
			while(strlen(currentWord) != 16) {
				strncat(currentWord, &space, 1);
			}
		}

		//I did this so it would be easier to keep track of the key
		unsigned char key[16];
		strcpy(key, currentWord);

		//Initializing the cipher context with the cipher mode
		EVP_CipherInit_ex(ctx, EVP_aes_128_cbc(), NULL, NULL, NULL, 1);

		//Checking the key and iv lengths
		OPENSSL_assert(EVP_CIPHER_CTX_key_length(ctx) == 16);
		OPENSSL_assert(EVP_CIPHER_CTX_iv_length(ctx) == 16);

		//Adding the key and the iv to the cipher context
		EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, 1);

		//First step in encrypting with EVP
		EVP_CipherUpdate(ctx, outbuf, &outlen, plainText, plainTextLen);

		//Setting the length to ensure the encryption output is the correct length
		cipherTextLen = outlen;

		//The final EVP function call that writes the encrypted output to outbuf
		EVP_CipherFinal_ex(ctx, outbuf + outlen, &outlen);

		cipherTextLen += outlen;

		//Allocate memory for the newly encrypted message
		//It makes it easier to change to hex and compare against the given ciphertext
		char *output = malloc(cipherTextLen*2+1);
		memset(output, 0, cipherTextLen*2+1);

		//Convert the encryption output into hex
		for (int x = 0; x < cipherTextLen; ++x) {
			char temp[5];
			sprintf(temp, "%02x", outbuf[x]);
			strcat(output, temp);
		}

		//Copy the output into another variable just to make it easier
		strcpy(hexedOutbuf, output);

		//This is the main check, if the newly generated output equals the given ciphertext then we have a match and the key is found
		if(strcmp(hexedOutbuf, cipherText) == 0) {
			found = true;
			printf("The key is: \'%s\'\n", key);
			printf("Original cipher text: %s\n", cipherText);
			printf("Encryption output: %s\n", hexedOutbuf);
		} else if(feof(wordList) && found == false) { //If no match is found, the loop will break and the program will end
			printf("No match was found!\n");
			break;

		}/*else {
			printf("Tried key: \'%s\'\n", key);
			printf("Output: %s\n", hexedOutbuf);
			printf("-----------------------------------------------------\n");
		}*/

		//All of the variables that are used throughout the encryption are reset to be empty
		strcpy(hexedOutbuf, "");
		strcpy(outbuf, "");
		strcpy(key, "");
		strcpy(currentWord, "");

		//The memory allocated earlier for the encryption output is freed
		free(output);

		//The cipher context is freed
		EVP_CIPHER_CTX_free(ctx);
	}

	//The wordList file is closed
	fclose(wordList);

	return 0;
}

