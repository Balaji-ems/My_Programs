#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8080 

int main(void)
{
	int sockfd,n,len;
	char buffer[1024]; 
	char msg[20];
	struct sockaddr_in  servaddr; 
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	if(sockfd < 0)  
		printf("\nSocket creation failed");
	else
		printf("\nSocket created successfully"); 

	memset(&servaddr, 0, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY;

	while(1) {
		printf("\nEnter the data to send the server : ");
		scanf("%s",msg);
		sendto(sockfd, (const char *)msg, strlen(msg),MSG_CONFIRM,
		       (const struct sockaddr *) &servaddr,sizeof(servaddr));
		if (!strcmp("end", msg))
			break;
	}
	close(sockfd); 
	return 0; 
}
