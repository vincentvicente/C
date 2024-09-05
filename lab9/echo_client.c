#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 999

void PrintBlue(char* str) {
  printf("\033[1;94m%s\033[0m", str);
}

void PrintYellow(char* str) {
  printf("\033[1;93m%s\033[0m", str);
}

char* Fgets(char *ptr, int n, FILE *stream) {
  char *rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}

int main() {
  struct addrinfo hints, *result;

  // Allows "global"
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;  /* IPv4 only */
  hints.ai_socktype = SOCK_STREAM;  /* TCP */

  int s;

  s = getaddrinfo("localhost",  // 127.0.0.1
                  "1234",  // port
                  &hints,
                  &result);

  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  connect(sock_fd, result->ai_addr, result->ai_addrlen);

  while (1) {
      // Read input from user
      char buffer[MAXLINE];
      printf("Enter your message: ");
      Fgets(buffer, MAXLINE, stdin);

      // Send the message to the server
      PrintYellow("\nSENDING: ");
      printf("%s\n", buffer);
      write(sock_fd, buffer, strlen(buffer));

      // Check if the message is to terminate the connection
      if (buffer[0] != 'x') {
          int repetitions;
          char repetitions_buffer[MAXLINE];
          printf("How many times to repeat?\n");
          Fgets(repetitions_buffer, MAXLINE, stdin);
          sscanf(repetitions_buffer, "%d", &repetitions);

          // Send the repetition count to the server
          write(sock_fd, repetitions_buffer, strlen(repetitions_buffer));

          // Receive and print the echoed messages from the server
          PrintBlue("\nFROM SERVER:\n");
          for (int i = 0; i < repetitions; i++) {
              int len = read(sock_fd, buffer, sizeof(buffer) - 1);
              buffer[len] = '\0';
              printf("%s\n", buffer);
          }
      } else {
          // If the message is to terminate the connection, break the loop
          printf("Connection terminates.\n");
          break;
      }
  }

  close(sock_fd);
}
