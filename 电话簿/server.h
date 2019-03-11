#ifndef SERVER_H
#define SERVER_H

//客户端结构体
typedef struct Cus
{
	int fd;
	char ip[20];
	
}Cus;
//消息结构体
typedef struct Mess
{
	int type;//消息类型
	char buf[1024];//消息数据
}Mess;
//服务器类
class Server
{
public:
	//服务器构造函数－绑定地址
	Server(int* sockfd);
	//等待连接
	void link_cli(int* sockfd);
	//线程函数
	static void* start(void* cus);
	//发送信息
	void send_mess(int fd,int index,char* mess);
	//接收信息
	char* recv_mess(int fd,char* str);
	//销毁服务器
	//~Server(void);
};
int run_server(void);
void start(void* fd);
#endif// SERVER_H
