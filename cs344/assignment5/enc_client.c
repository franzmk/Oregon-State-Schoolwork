#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>  // ssize_t
#include <sys/socket.h> // send(),recv()
#include <netdb.h>      // gethostbyname()

/**
* Client code
* 1. Create a socket and connect to the server specified in the command arugments.
* 2. Prompt the user for input and send that input as a message to the server.
* 3. Print the message received from the server and exit the program.
*/

// Error function used for reporting issues
void error(const char *msg) {
  perror(msg);
  exit(0);
}

// Set up the address struct
void setupAddressStruct(struct sockaddr_in* address,
                        int portNumber,
                        char* hostname){

  // Clear out the address struct
  memset((char*) address, '\0', sizeof(*address));

  // The address should be network capable
  address->sin_family = AF_INET;
  // Store the port number
  address->sin_port = htons(portNumber);

  // Get the DNS entry for this host name
  struct hostent* hostInfo = gethostbyname(hostname);
  if (hostInfo == NULL) {
    fprintf(stderr, "CLIENT: ERROR, no such host\n");
    exit(0);
  }
  // Copy the first IP address from the DNS entry to sin_addr.s_addr
  memcpy((char*) &address->sin_addr.s_addr,
        hostInfo->h_addr_list[0],
        hostInfo->h_length);
}

int main(int argc, char *argv[]) {
  int socketFD, portNumber, charsWritten, charsRead;
  struct sockaddr_in serverAddress;
  char buffer[140010], smBuff[1000];
  int bufferIndex = 4, plaintextLen = 0, keyLen = 0;

  memset(buffer, '\0', 140010);
  memset(smBuff, '\0', 1000);

  // Check usage & args
  if (argc < 4) {
    fprintf(stderr,"USAGE: %s plaintext key port\n", argv[0]);
    exit(0);
  }

  // Create a socket
  socketFD = socket(AF_INET, SOCK_STREAM, 0);
  if (socketFD < 0){
    error("CLIENT: ERROR opening socket");
  }

   // Set up the server address struct
  setupAddressStruct(&serverAddress, atoi(argv[3]), "localhost");

  // Connect to server
  if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
    error("CLIENT: ERROR connecting");
  }

  buffer[0] = 'e';
  buffer[1] = 'n';
  buffer[2] = 'c';
  buffer[3] = ';';

  FILE *plaintext = fopen(argv[1], "r");

  if(plaintext == NULL) {
    error("CLIENT: Error opening plaintext file!");
  } else {
      int c;
      while((c = fgetc(plaintext)) != EOF) {
        if(c != '\n') {
	  buffer[bufferIndex] = c;
          bufferIndex++;
	  plaintextLen++;
        }
      }
  }

  fclose(plaintext);

  buffer[bufferIndex] = ';';
  bufferIndex++;

  FILE *key = fopen(argv[2], "r");

  if(key == NULL) {
    error("CLIENT: Error opening key file!");
  } else {
      int c;
      while((c = fgetc(plaintext)) != EOF) {
        if(c != '\n') {
          buffer[bufferIndex] = c;
          bufferIndex++;
	  keyLen++;
        }
      }
  }

  fclose(key);

  buffer[bufferIndex] = '@';
  bufferIndex++;

  if(keyLen < plaintextLen) {
    error("ERROR: The selected key is too short");
  }

  //printf("%s\n", buffer);

  buffer[strcspn(buffer, "\n")] = '\0';


  // Plaintext check
  


//loop here
  const char *p = buffer;
  int buffLength = strlen(buffer);

  while(buffLength > 0) {
    //printf("client sending\n");
    charsWritten = send(socketFD, buffer, buffLength, 0);

    if (charsWritten <= 0){
      error("CLIENT: ERROR writing to socket");
    }

    p += charsWritten;
    buffLength -= charsWritten;
  }


  // Get return message from server
  // Clear out the buffer again for reuse
  memset(buffer, '\0', 140010);
  memset(smBuff, '\0', 1000);

  while(strstr(smBuff, "@") == NULL) {
    //printf("client receiving\n");
    // Read data from the socket
    charsRead = recv(socketFD, smBuff, 1000, 0);
    if (charsRead < 0){
      error("CLIENT: ERROR reading from socket");
    }
    strcat(buffer, smBuff);
  }

  if(buffer[0] == ':' && buffer[1] == ':') {
    error("Wrong client connected");
  }

  buffer[plaintextLen] = '\n';
  for(int x = 0; x < plaintextLen + 1; x++) {
    fprintf(stdout, "%c", buffer[x]);
  }

  memset(buffer, '\0', 140010);
  // Close the socket
  close(socketFD);
  return 0;
}
