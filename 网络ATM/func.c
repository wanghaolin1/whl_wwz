#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include "func2.h"

void creat(int fd,Acc* acc)
{
	char send_buf[1024];
	int acc_id = creat_id();
	acc->id = acc_id;
	if(-1 == user_creat(acc))
	{
		printf("开户失败\n");
		memset(send_buf,0,1024);
		strcpy(send_buf,"开户失败");
		send(fd,send_buf,strlen(send_buf) + 1,0); 
	}
	else
	{
		printf("%d:开户成功\n",acc_id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:开户成功",acc_id);
		send(fd,send_buf,strlen(send_buf) + 1,0); 
	}
}

void load(int fd,Acc* acc)
{
	char send_buf[1024];
	// 登录
	int flag = user_load(acc);
	if(-1 == flag)
	{
		printf("登录失败\n",acc->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"登录失败",acc->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else if(-2 == flag)
	{
		printf("%d:冻结\n",acc->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:冻结",acc->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else if(-3 == flag)
	{
		printf("用户不存在\n");
		memset(send_buf,0,1024);
		strcpy(send_buf,"用户不存在");
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else if(-4 == flag)
	{
		printf("用户已在线\n");
		memset(send_buf,0,1024);
		strcpy(send_buf,"用户已在线");
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else
	{
		printf("登录成功\n",acc->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"登录成功",acc->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
}

void save(int fd,Acc* acc)
{
	char send_buf[1024];
	double num = acc->money;
	if(-1 == user_save(acc))
	{
		printf("%d:存入失败\n",acc->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:存入失败",acc->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else
	{
		printf("%d:成功存入%.2lf$\n",acc->id,num);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:成功存入%.2lf$,账户余额:%.2lf$",acc->id,num,acc->money);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
}

void take(int fd,Acc* acc)
{
	char send_buf[1024];
	double num = acc->money;
	if(-1 == user_take(acc))
	{
		printf("%d:取出失败\n",acc->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:取出失败",acc->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else
	{
		printf("%d:成功取出:%.2lf$\n",acc->id,num);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:成功取出:%.2lf$,账户余额:%.2lf$",acc->id,num,acc->money);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
}

void query(int fd,Acc* acc)
{
	char send_buf[1024];
	if(-1 == user_query(acc))
		{
			printf("%d:查询余额失败\n",acc->id);
			memset(send_buf,0,1024);
			sprintf(send_buf,"%d:查询余额失败",acc->id);
			send(fd,send_buf,strlen(send_buf) + 1,0);
		}
		else
		{
			printf("%d:查询余额成功\n",acc->id);
			memset(send_buf,0,1024);
			sprintf(send_buf,"%d余额剩余:%.2lf$",acc->id,acc->money);
			send(fd,send_buf,strlen(send_buf) + 1,0);
		}
}

void trans(int fd,Tra* tra)
{
	char send_buf[1024];
	if(-1 == user_trans(tra))
	{
		printf("转账失败\n");
		memset(send_buf,0,1024);
		strcpy(send_buf,"转账失败");
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else
	{
		printf("转账成功\n");
		memset(send_buf,0,1024);
		strcpy(send_buf,"转账成功");
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
}

void modify(int fd,Mod* mod)
{
	char send_buf[1024];
	if(-1 == user_modify(mod))
	{
		printf("%d:修改失败\n",mod->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:修改失败",mod->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else
	{
		printf("%d:修改成功\n",mod->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:修改成功",mod->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
}

void unlock(int fd,Acc* acc)
{
	char send_buf[1024];
	if(-1 == user_unlock(acc))
	{
		printf("%d:解锁失败\n",acc->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:解锁失败",acc->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else
	{
		printf("%d:解锁成功\n",acc->id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:解锁成功",acc->id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
}
void destory(int fd,Acc* acc)
{
	char send_buf[1024];
	int id = acc->id;
	if(-1 == user_destory(acc))
	{
		printf("%d:销户失败\n",id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:销户失败,请查看是否还有余额",id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
	else
	{
		printf("%d:销户成功\n",id);
		memset(send_buf,0,1024);
		sprintf(send_buf,"%d:销户成功",id);
		send(fd,send_buf,strlen(send_buf) + 1,0);
	}
}
