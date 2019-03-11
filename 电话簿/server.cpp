#include "server.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std;
//发送信息
void Server::send_mess(int fd,int index,char* mess)
{
	Mess buf;
	buf.type = index;
	strcpy(buf.buf,mess); 
	send(fd,&buf,sizeof(Mess),0);	
}
//接收信息
char* Server::recv_mess(int fd,char* str)
{
	Mess buf;
	recv(fd,&buf,sizeof(Mess),0);	 
	sprintf(str,"%d-%s",buf.type,buf.buf);
	return str;
}

//服务器线程
void* Server::start(void* cus)
{
	int fd = ((Cus*)cus)->fd;
	
	Mess buf_mess;
	char buf_quit[1024] = {};
	
	while(true)
	{
		//如果用户退出
		if (0 >= recv(fd,&buf_mess,sizeof(buf_mess),0))
		{
			sprintf(buf_quit,"%s \33[;31m%s\33[0m ",((Cus*)cus)->ip,"已退出！");
			puts(buf_quit);
			//结束线程
           	pthread_exit((void*)fd);
		}
		printf("%s   :%d----%s\n",((Cus*)cus)->ip,buf_mess.type,buf_mess.buf);
	
	}
}
//服务器构造函数－绑定地址
Server::Server(int* sockfd)
{
	// 创建socket对象
	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(0 > *sockfd)
	{
		perror("socket");
		return;
	}

	// 准备通信地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1991);
	addr.sin_addr.s_addr = inet_addr("192.168.1.138");
	// 绑定socket对象与通信地址
	socklen_t len = sizeof(addr);
	if(0 > bind(*sockfd,(sockaddr*)&addr,len))
	{
		perror("bind");
		return;
	}

	// 设置监听socket对象
	listen(*sockfd,10);
	printf("正在监听．．．");
}
//等待连接
void Server::link_cli(int* sockfd)
{
	pthread_t id;
	// 准备通信地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1998);
	addr.sin_addr.s_addr = inet_addr("192.168.1.138");
	socklen_t len = sizeof(addr);
	while(1)
	{
		struct sockaddr_in from_addr;
		Cus* cus = (Cus*)malloc(sizeof(Cus));
		int newfd = accept(*sockfd,(sockaddr*)&from_addr,&len);
		if(0 > newfd)
		{
			perror("accept");
			return;
		}
		printf("客户端:%s连接成功!\n",inet_ntoa(from_addr.sin_addr));
		cus->fd = newfd;
		strcpy(cus->ip,inet_ntoa(from_addr.sin_addr));
		printf("链接的ＩＰ地址是%s\n",cus->ip);
		pthread_create(&id,NULL,start,(void*)cus);

		pthread_detach(id);
	}
	cout << "结束了？？" << endl;
	close(*sockfd);
}

