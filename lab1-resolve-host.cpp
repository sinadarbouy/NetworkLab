#include <stdio.h>
#include <stddef.h>

#include <assert.h>
#include <limits.h>
#include <unistd.h>

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
	
	if(argc!=2){
	    printf("the program needs just one parameter \n");
	    return 1;
	}

	const char* remoteHostName = argv[1];
	
	const size_t kHostNameMaxLength = HOST_NAME_MAX+1;
	char localHostName[kHostNameMaxLength];
	gethostname( localHostName, kHostNameMaxLength);

	struct addrinfo hints;
	struct addrinfo *result;
        int s;
	memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_INET;    
        hints.ai_socktype = SOCK_STREAM; 
        //hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
        hints.ai_protocol = IPPROTO_TCP; /* won’t get “duplicate” IPv4 addresses */ 
        //hints.ai_canonname = NULL;
	//hints.ai_addr = NULL;
        //hints.ai_next = NULL;

	s = getaddrinfo(remoteHostName, NULL, &hints, &result);
	if (s != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s)); // human-readable
            exit(EXIT_FAILURE);
        }
        

        struct sockaddr_in *addr;
        addr = (sockaddr_in *)result->ai_addr; 
        printf("%s has address %s\n",remoteHostName,inet_ntoa((in_addr)addr->sin_addr));
}
