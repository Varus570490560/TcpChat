#include<stdio.h>
#include<sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(){
    int listenfd,connfd;
    struct sockaddr_in servaddr;
    if((listenfd = socket(AF_INET,SOCK_STREAM,0)==-1)){
        printf("Create socket error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }
    memset(&servaddr,0,sizeof (servaddr));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8888);
    servaddr.sin_family = AF_INET;

    if((bind(listenbfd,(sockaddr*)&servaddr,sizeof(servaddr))==-1)){
        printf("Bind error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }

    if((listen(listenfd,10)==-1)){
        printf("Listen error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }

    if((connfd = accept(listenfd,NULL,NULL))==-1){
        printf("Accept error:[%d]%s\n",errno,strerror(errno));
        return 0;
    }



}