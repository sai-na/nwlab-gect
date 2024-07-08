#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define MAX 1024
#define PORT 12345

int main()
{
    struct sockaddr_in server, client;
    socklen_t len = sizeof(server);
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    char buff[MAX];

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    printf("Server listening...\n");
    
    recvfrom(sockfd, buff, MAX, 0, (struct sockaddr *)&client, &len);

    FILE *fptr;
    fptr = fopen("mail.txt", "w");
    fprintf(fptr, "%s", buff);
    fclose(fptr);

    printf("\nMail recieved and saved to mail.txt\n");

    close(sockfd);
}