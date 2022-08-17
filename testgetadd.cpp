#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc,char *argv[]){
    int sock;
    struct addrinfo hints,*res;
    int n;
    int err;
    if(argc != 2){
        fprintf(stderr,"Usage : %s dst \n",argv[0]);
        return 1;
    } 
    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_DGRAM;
    err = getaddrinfo(argv[1],"12345",&hints,&res);
    if(err != 0){
        perror("getaddrinfo");
        printf("getaddrinfo %s\n",strerror(errno));
        printf("getaddrinfo : %s \n",gai_strerror(err));
        return 1;
    }

    sock = socket(res->ai_family,res->ai_socktype,0);
    if(sock < 0){
        perror("socket");
        return 1;

        const char *ipverstr;
        switch (res->ai_family){
            case AF_INET:
                ipverstr = "IPv4";
                break;
            case AF_INET6:
                ipverstr = "IPv6";
                break;
            default:
                ipverstr = "unknown";
                break;            
        }
        printf("ipverstr = %s\n ",ipverstr);            
    }
    n = sendto(sock,"HELLO",5,0,res->ai_addr,res->ai_addrlen);
    if(n<1){
        perror("sendto");
        return 1;
    }
    struct sockaddr_in *addr;
    addr = (struct sockaddr_in *)res->ai_addr; 
    printf("inet_ntoa(in_addr)sin = %s\n",inet_ntoa((struct in_addr)addr->sin_addr));

    printf("############ finish !! #######\n");
    close(sock);
    freeaddrinfo(res);
    return 0;
}
