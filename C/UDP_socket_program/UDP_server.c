#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT       8080
#define MAX_BUFFER 1024

int main(void)
{
	int sockfd, len, n;
	char buffer[MAX_BUFFER];
	struct sockaddr_in servaddr, cliaddr;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
		printf("Socket creation failed");
	else
		printf("Socket created successfully");

	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);

	if (bind(sockfd, (const struct sockaddr *)&servaddr,
		 sizeof(servaddr)) < 0)
		printf("\nBinding failed");
	else
		printf("\nBinding Successful");
	while (1) {
		n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL,
			     (struct sockaddr *)&cliaddr, &len);
		buffer[n] = '\0';
		printf("\nData from client : %s\n", buffer);

		if (!strcmp(buffer, "end"))
			break;
	}

	close(sockfd);

	return 0;
}
