#ifndef __PROTOCOLUTIL_HPP__
#define __PROTOCOLUTIL_HPP__

#include<iostream>
#include<stdlib.h>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;

#define NORMAL 0
#define WARNING 1
#define ERROR 2

//错误级别数组
const char* ErrLevel[]={
    "Normal",
    "Warning",
    "Error"
};

void log(string msg,int level,string file,int line)
{
    cout<<file<<" : "<<line<<" : "<<msg<<" "<<ErrLevel[level]<<endl;
}

#define LOG(msg,level) log(msg,level,__FILE__,__LINE__);
class SocketApi
{
    public:
       static int Socket()
        {
            int sock=socket(AF_INET,SOCK_STREAM,0);
            if(sock < 0)
            {
                LOG("sock create error!",ERROR);
                exit(2);
            }
            return sock;
        }
        static void Bind(int sock,int port)
        {
            struct sockaddr_in local;
            //清空local
            bzero(&local,sizeof(local));
            local.sin_family=AF_INET;
            //动态绑定ip地址
            local.sin_addr.s_addr=htonl(INADDR_ANY);
            local.sin_port=htons(port);
            if(bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0)
            {
                LOG("bind error!",ERROR);
                exit(3);
            }
        }
        static void Listen(int sock)
        {
            const int backlog=5;
            if(listen(sock,backlog)<0)
            {
                LOG("listen error!",ERROR);
                exit(4);
            }
        }
        static int Accept(int listen_sock,string &ip,int &port)
        {
            struct sockaddr_in peer;    //填写客户端的sockaddr_in
            socklen_t  len=sizeof(peer);
            int sock=accept(listen_sock,(struct sockaddr*)&peer,&len);
            if(sock<0)
            {
                LOG("accept error!",WARNING);
                exit(4);
            }
            port=ntohs(peer.sin_port);
            ip=inet_ntoa(peer.sin_addr);    //这里不用写成peer.sin_addr.s_addr的原因是这里是传参，不是赋值。传进去的结构体初始化为一个匿名的实体
            return sock;
        }
};

class Entry
{
    public:
        static void* HandlerRequest(void* arg)    //处理客户端的请求
        {
            pthread_detach(pthread_self());
            int sock=*(int*)arg;
            delete arg;

            char buf[10240];
            read(sock,buf,sizeof(buf));
            cout<<buf<<endl;
            close(sock);
        }
};
#endif
