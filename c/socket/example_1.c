/*
 * Here’s an example of a very simple socket client program, client1.c.
 * It creates an unnamed socket and connects it to a server socket called
 * server_socket. We cover the details of the socket system call a
 * little later, after we’ve discussed some addressing issues.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int sockfd, len;
	struct sockaddr_un address;
	int result;
	char ch = 'a';

	// Create a socket for the client
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	// Name the socket as agreed with the server
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);

	// Connect your socket to  the server's socket
	result = connect(sockfd, (struct sockaddr *)&address, len);

	if (result == -1) {
		perror("oops: client");
		exit(1);
	}

	// You can now read and read write via sockfd
	
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("char from server = %c\n", ch);
	close(sockfd);
	exit(0);
	/*
	 * This program fails when you run it because you haven't yet created the
	 * server-side named socket. (The exact error message may differ from
	 * system to system)
	 */
}
