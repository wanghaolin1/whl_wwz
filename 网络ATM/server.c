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
#include "struct.h"
#include "func.h"
#include "func2.h"
typedef struct sockaddr SockAddr;


void* run(void* newfd)
{
	int fd = (int)newfd;
	char send_buf[1024];
	char recv_buf[1024];
	while(1)
	{
		memset(recv_buf,0,1024);
		int ret = recv(fd,recv_buf,1024,0);
		if(ret == sizeof(Acc))
		{
			Acc acc = {};
			memcpy(&acc,recv_buf,sizeof(Acc));
			if(acc.res == MY_CREAT)
			{
				creat(fd,&acc);
			}
			else if(acc.res == MY_LOAD)
			{
				load(fd,&acc);
			}
			else if(acc.res == MY_SAVE)
			{
				save(fd,&acc);
			}
			else if(acc.res == MY_TAKE)
			{
				take(fd,&acc);
			}
			else if(acc.res == MY_QUERY)
			{
				query(fd,&acc);
			}
			else if(acc.res == UNLOCK)
			{
				unlock(fd,&acc);
			}
			else if(acc.res == MY_DESTORY)
			{
				destory(fd,&acc);
			}
			else if(acc.res == MY_EXIT)
			{
				atm_exit(&acc);
			}
		}
		else if(ret == sizeof(Tra))
		{
			Tra tra = {};
			memcpy(&tra,recv_buf,sizeof(Tra));
			if(tra.res == MY_TRANS)
			{
				trans(fd,&tra);
			}
		}
		else if(ret == sizeof(Mod))
		{
			Mod mod = {};
			memcpy(&mod,recv_buf,sizeof(Mod));
			if(mod.res == MY_MODIFY)
			{
				modify(fd,&mod);
			}
		}
		else
			break;
	}
}

int main()
{
	// 创建socket对象
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(0 > sockfd)
	{
		perror("socket");
		return -1;
	}

	// 准备通信地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1999);
	addr.sin_addr.s_addr = inet_addr("192.168.1.121");
	
	// 绑定socket对象与通信地址
	socklen_t len = sizeof(addr);
	if(0 > bind(sockfd,(SockAddr*)&addr,len))
	{
		perror("bind");
		return -1;
	}

	// 设置监听socket对象
	listen(sockfd,10);

	pthread_t id;
	while(1)
	{
		struct sockaddr_in from_addr;
		int newfd = accept(sockfd,(SockAddr*)&from_addr,&len);
		if(0 > newfd)
		{
			perror("accept");
			return -1;
		}
		printf("ATM客户端:%s连接成功!\n",inet_ntoa(from_addr.sin_addr));

		pthread_create(&id,NULL,run,(void*)newfd);

		pthread_detach(id);
	}
	close(sockfd);
	return 0;
}
