#include <cstdio>
#include <sys/socket.h>
#include <cerrno>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#define MAXLINE 4096

int main(){
    char buffer[MAXLINE];
    int listenfd,connfd;
    ssize_t n;
    struct sockaddr_in servaddr={};
    if((listenfd = socket(AF_INET,SOCK_STREAM,0))==-1){
        printf("Create socket error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }
    printf("%d\n",listenfd);
    memset(&servaddr,0,sizeof (servaddr));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8888);
    servaddr.sin_family = AF_INET;
    if((bind(listenfd,(sockaddr*)&servaddr,sizeof(servaddr))==-1)){
        printf("Bind error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }

    if((listen(listenfd,10)==-1)){
        printf("Listen error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }

    if((connfd = accept(listenfd,nullptr,nullptr))==-1){
        printf("Accept error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }
    memset(buffer,0,MAXLINE);
    n = recv(connfd,buffer,MAXLINE,0);
    buffer[n]='\0';
    printf("%s\n",buffer);
    close(connfd);
    return 0;
}