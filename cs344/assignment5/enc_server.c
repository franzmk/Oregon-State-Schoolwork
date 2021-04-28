#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Error function used for reporting issues
void error(const char *msg) {
  perror(msg);
  exit(1);
}

// Set up the address struct for the server socket
void setupAddressStruct(struct sockaddr_in* address,
                        int portNumber){

  // Clear out the address struct
  memset((char*) address, '\0', sizeof(*address));

  // The address should be network capable
  address->sin_family = AF_INET;
  // Store the port number
  address->sin_port = htons(portNumber);
  // Allow a client at any address to connect to this server
  address->sin_addr.s_addr = INADDR_ANY;
}

int main(int argc, char *argv[]){
  int connectionSocket, charsRead, plaintextLen = 0;;
  char smBuffer[1000], buffer[140010], encBuff[70001], plaintext[70000], key[70000];
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t sizeOfClientInfo = sizeof(clientAddress);

  // Check usage & args
  if (argc < 2) {
    fprintf(stderr,"USAGE: %s port\n", argv[0]);
    exit(1);
  }

  // Create the socket that will listen for connections
  int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (listenSocket < 0) {
    error("ERROR opening socket");
  }

  // Set up the address struct for the server socket
  setupAddressStruct(&serverAddress, atoi(argv[1]));

  // Associate the socket to the port
  if (bind(listenSocket,
          (struct sockaddr *)&serverAddress,
          sizeof(serverAddress)) < 0){
    error("ERROR on binding");
  }

  // Start listening for connetions. Allow up to 5 connections to queue up
  listen(listenSocket, 5);

  // Accept a connection, blocking if one is not available until one connects
  while(1){
    // Accept the connection request which creates a connection socket
    connectionSocket = accept(listenSocket,
                (struct sockaddr *)&clientAddress,
                &sizeOfClientInfo);
    if (connectionSocket < 0){
      error("ERROR on accept");
    }

    /*pid_t pid = fork();

    if(pid == 0) {
      childProcess();
      exit(0);
    }*/

    //printf("SERVER: Connected to client running at host %d port %d\n",
                          //ntohs(clientAddress.sin_addr.s_addr),
                          //ntohs(clientAddress.sin_port));

    // Get the message from the client and display it
    memset(buffer, '\0', 140010);
    memset(smBuffer, '\0', 1000);

    while(strstr(smBuffer, "@") == NULL) {
      //printf("server receiving\n");
      // Read the client's message from the socket
      charsRead = recv(connectionSocket, smBuffer, 1000, 0);
      if (charsRead < 0){
        error("ERROR reading from socket");
      }
      strcat(buffer, smBuffer);
    }

    //printf("SERVER: %s\n", buffer);

    if(buffer[0] != 'e' && buffer[1] != 'n') {
      //error("ERROR: Decryption client attempted to connect, shutting socket down");
      charsRead = send(connectionSocket, "::@", 3, 0);
    }

    int i = 4, j = 0;
    while(buffer[i] != ';') {
      plaintext[j] = buffer[i];
      i++;
      j++;
      plaintextLen++;
    }

    i++;
    j = 0;
    while(buffer[i] != '@') {
      key[j] = buffer[i];
      i++;
      j++;
    }

    //printf("SERVER: plaintext-\"%s\" key-\"%s\"\n", plaintext, key);

    memset(encBuff, '\0', sizeof(encBuff));

    //enc here
    for(int x = 0; x < plaintextLen; x++) {
      char plainVal, keyVal, temp;

      if(plaintext[x] == ' ') {
        plainVal = 26;
      } else {
        plainVal = plaintext[x] - 65;
      }

      if(key[x] == ' ') {
        keyVal = 26;
      } else {
        keyVal = key[x] - 65;
      }

      temp = ((plainVal + keyVal) % 26) + 65;

      encBuff[x] = temp;
    }

    memset(plaintext, '\0', 70000);
    memset(key, '\0', 70000);

    encBuff[plaintextLen] = '\n';
    //printf("SERVER: %d  %s\n", sizeof(encBuff), encBuff);

    // Send a Success message back to the client
    const char *p = encBuff;
    int buffLength = sizeof(encBuff);
    encBuff[buffLength-1] = '@';

    while(buffLength > 0) {
      //printf("server sending\n");
      charsRead = send(connectionSocket, encBuff, buffLength, 0);
      if (charsRead <= 0){
        error("ERROR writing to socket");
      }
      p += charsRead;
      buffLength -= charsRead;
    }

    memset(encBuff, '\0', sizeof(encBuff));
    //printf("Server: encBuff after memset: %s\n", encBuff);

    // Close the connection socket for this client
    close(connectionSocket);
  }
  // Close the listening socket
  close(listenSocket);
  return 0;
}

