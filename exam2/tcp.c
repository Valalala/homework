//Walter Rasmussen - Spring 2018
// Webpage fetch using tcp
//tcp.c
// Code taken from nolim1t on github
// https://gist.github.com/nolim1t/126991

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int socket_connect(char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int on = 1, sock;  
	//int sock;

	if((hp = gethostbyname(host)) == NULL){
		herror("gethostbyname");
		exit(1);
	}
	//bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	memset(&addr, '0', sizeof(addr));

	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	
	//if(inet_pton(AF_INET, hp->h_addr_list[0], &addr.sin_addr)<=0) {
	//	printf("\nInvalid address/ Address not supported \n");
	//	return -1;
	//}
	//addr.sin_addr.s_addr = *(long*)(hp->h_addr_list[0]);
	//addr.sin_addr = hp->h_addr_list[0];
	sock = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

	if(sock < 0){
		perror("setsockopt");
		exit(1);
	}
	
	//if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) < 0){
	if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
		perror("connect");
		exit(1);

	}
	return sock;
}
 
#define BUFFER_SIZE 1024
#define REQUEST "GET /index.html HTTP/1.1\\r\\nhost: myhost\\r\\n\\r\\n"

int main(int argc, char *argv[]){
	int fd;
	char buffer[BUFFER_SIZE];

	if(argc < 3){
		fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
		exit(1); 
	}
       
	fd = socket_connect(argv[1], atoi(argv[2])); 
	write(fd, REQUEST, strlen(REQUEST)); // write(fd, char[]*, len);  
	bzero(buffer, BUFFER_SIZE);
	
	while(read(fd, buffer, BUFFER_SIZE - 1) != 0){
		printf("%s\n", buffer);
		bzero(buffer, BUFFER_SIZE);
	}

	shutdown(fd, SHUT_RDWR); 
	close(fd); 

	return 0;
}
