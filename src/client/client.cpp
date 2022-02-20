//
// Created by Varus on 2022/2/20.
//
#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cerrno>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "192.168.184.128"

int main(){
    int sockfd;
    char sendline[4096];
    struct sockaddr_in servaddr={};
    if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
        printf("Create socket error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }
    memset(&servaddr,0,sizeof (servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    if(inet_pton(AF_INET,SERVER_IP,&servaddr.sin_addr)<=0){
        printf("inet_pton error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof (servaddr))<0){
        printf("Connect error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }

    printf("Input msg to server\n");
    fgets(sendline,4096,stdin);
    if(send(sockfd,sendline,strlen(sendline),0)<0){
        printf("Send error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }
    close(sockfd);
    return 0;
}
