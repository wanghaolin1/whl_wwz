#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include "struct.h"
#include "tools.c"

const char* ID_FILE = "./account/id.dat";

/*获取一个不唯一的卡号*/
int creat_id()
{
	static int num = 1000000;
	/*当文件不存在时,返回-1,存在返回0*/
	if(0 > access(ID_FILE,0))
	{
		/*不存在时,创建文件*/
		int fd = open(ID_FILE,O_CREAT|O_WRONLY|O_EXCL,0644);
		if(0 > fd)
		{
			printf("文件打开失败\n");
			return -1;
		}
		/*将num写入文件中*/
		write(fd,&num,sizeof(num));
		close(fd);
		return num;
	}
	else
	{
		/*以读写权限打开文件*/
		int fd = open(ID_FILE,O_RDWR);
		if(0 > fd)
		{
			printf("文件打开失败\n");
			return -1;
		}
		/*读取文件里的数*/
		read(fd,&num,sizeof(num));
		num++;
		/*将文件指针移到最后的位置*/
		lseek(fd,0,SEEK_SET);
		/* 将新的num写入文件中*/
		write(fd,&num,sizeof(num));
		close(fd);
		return num;
	}
}

/*创建账号,存到文件中*/
int user_creat(Acc* acc)
{
	char filename[20] = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*创建文件,如果存在则创建失败*/
	int fd = open(filename,O_CREAT|O_WRONLY|O_EXCL,0644);
	if(0 > fd)
	{
		printf("开户失败\n");
		return -1;
	}
	/*登录次数初始设为3*/
	acc->cnt = 3;
	Acc* accsave = acc;
	/*将账号信息加密写入文件中*/
	encry(accsave,sizeof(Acc));
	write(fd,accsave,sizeof(Acc));
	close(fd);
	return 0;
}
/*登录信息判断*/
int user_load(Acc* acc)
{
	char filename[20] = {};
	Acc accsave = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*以读写权限打开该文件*/
	int fd = open(filename,O_RDWR);
	if(0 > fd)
	{
		printf("用户不存在\n");
		return -3;
	}
	/*读入该文件的信息,并解密*/
	read(fd,&accsave,sizeof(Acc));
	encry(&accsave,sizeof(Acc));
	/*账户是否被锁住*/
	if(accsave.cnt == 0)
	{
		printf("锁住\n");
		return -2;
	}
	/*对比密码*/
	printf("输入的密码=%s 记录的密码=%s\n",acc->password,accsave.password);
	if(0 != strcmp(acc->password,accsave.password))
	{
		/*将登录次数减1,加密后重新覆盖写入文件*/
		printf("登录失败\n");
		accsave.cnt--;
		acc->cnt = accsave.cnt;
		printf("剩余次数 = %d\n",accsave.cnt);
		/*加密*/
		encry(&accsave,sizeof(Acc));
		lseek(fd,0,SEEK_SET);
		write(fd,&accsave,sizeof(Acc));
		close(fd);
		if(acc->cnt == 0)
			return -2;
		return -1;
	}
	if(1 == accsave.online)
	{
		accsave.cnt = 3;
		encry(&accsave,sizeof(Acc));
		lseek(fd,0,SEEK_SET);
		write(fd,&accsave,sizeof(Acc));
		close(fd);
		return -4;
	}
	/*登入成功,登录次数重新置位3,然后加密重新覆盖写入文件*/
	accsave.cnt = 3;
	accsave.online = 1;
	encry(&accsave,sizeof(Acc));/*加密*/
	lseek(fd,0,SEEK_SET);
	write(fd,&accsave,sizeof(Acc));
	close(fd);
	return 0;
}
void atm_exit(Acc* acc)
{
	char filename[20] = {};
	Acc accsave = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*以读写权限打开用户文件*/
	int fd = open(filename,O_RDWR);
	if(0 > fd)
	{
		printf("文件打开失败\n");
		return ;
	}
	/*读入该文件的信息,并解密*/
	read(fd,&accsave,sizeof(Acc));
	encry(&accsave,sizeof(Acc));
	/*把在线状态改成下线状态*/
	accsave.online = 0;
	/*加密*/
	encry(&accsave,sizeof(Acc));
	lseek(fd,0,SEEK_SET);
	write(fd,&accsave,sizeof(Acc));
	close(fd);
	return ;
}
/*存钱*/
int user_save(Acc* acc)
{
	char filename[20] = {};
	Acc accsave = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*以读写权限打开用户文件*/
	int fd = open(filename,O_RDWR);
	if(0 > fd)
	{
		printf("文件打开失败\n");
		return -1;
	}
	/*读入该文件的信息,并解密*/
	read(fd,&accsave,sizeof(Acc));
	encry(&accsave,sizeof(Acc));
	/*执行存钱操作,然后重新覆盖写入文件*/
	accsave.money += acc->money;
	/*返回存入后的钱,告知客户端*/
	acc->money = accsave.money;
	/*加密*/
	encry(&accsave,sizeof(Acc));
	lseek(fd,0,SEEK_SET);
	write(fd,&accsave,sizeof(Acc));
	close(fd);
	return 0;
}
/*取钱*/
int user_take(Acc* acc)
{
	char filename[20] = {};
	Acc accsave = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*以读写权限打开用户文件*/
	int fd = open(filename,O_RDWR);
	if(0 > fd)
	{
		printf("文件打开失败\n");
		return -1;
	}
	/*读入该文件的信息,并解密*/
	read(fd,&accsave,sizeof(Acc));
	encry(&accsave,sizeof(Acc));
	/*进行取钱操作*/
	accsave.money -= acc->money;
	/*判断是否有那么多钱,没有则直接返回*/
	if(0 > accsave.money)
	{
		printf("余额不足\n");
		close(fd);
		return -1;
	}
	/*返回取钱后的钱,通知客户端*/
	acc->money = accsave.money;
	/*将文件指针移到开头*/
	lseek(fd,0,SEEK_SET);
	/*加密*/
	encry(&accsave,sizeof(Acc));
	write(fd,&accsave,sizeof(Acc));
	close(fd);
	return 0;
}
/*查询余额*/
int user_query(Acc* acc)
{
	char filename[20] = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*以只读权限打开用户文件*/
	int fd = open(filename,O_RDONLY);
	if(0 > fd)
	{
		printf("文件打开失败\n");
		return -1;
	}
	/*读入该文件信息,并解密*/
	read(fd,acc,sizeof(Acc));
	encry(acc,sizeof(Acc));
	close(fd);
	return 0;
}
/*转账*/
int user_trans(Tra* tra)
{
	Acc acc_my = {};
	Acc acc_obj = {};
	char filename_obj[20] = {};
	/*将转账用户和被转账用户的卡号作为输入,作为文件名*/
	sprintf(filename_obj,"./account/%d",tra->id_obj);
	/*判断被转账用户是否存在*/
	if(0 > access(filename_obj,0))
	{
		printf("文件打开失败\n");
		return -1;
	}
	/*将2个用户卡号存入结构体中,调用存钱取钱的函数执行转账*/
	acc_my.id = tra->id_my;
	acc_obj.id = tra->id_obj;
	acc_my.money = tra->money;
	acc_obj.money = tra->money;
	/*因为要判断是否有那么多钱,所以要先调用取钱的函数*/
	if(0 > user_take(&acc_my))
		return -1;
	user_save(&acc_obj);
	return 0;
}
/*销户*/
int user_destory(Acc* acc)
{
	char filename[20] = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*以只读权限打开用户文件*/
	int fd = open(filename,O_RDONLY);
	if(0 > fd)
	{
		printf("文件打开失败\n");
		return -1;
	}
	/*读入该文件信息,并解密*/
	read(fd,acc,sizeof(Acc));
	encry(acc,sizeof(Acc));
	close(fd);
	/*有余额销户失败*/
	if(0 < acc->money)
	{
		printf("还有余额:%.2lf$",acc->money);
		return -1;
	}
	/*删除文件*/
	int ret = remove(filename);
	if(0 > ret)
	{
		printf("删除失败\n");
		return -1;
	}
	/*在delete_account里创建文件,记录删除的用户*/
	char filename_delete[40] = {};
	sprintf(filename_delete,"./delete account/%d",acc->id);
	int fd_delete = open(filename_delete,O_CREAT|O_WRONLY|O_EXCL,0644);
	if(0 > fd_delete)
	{
		return -1;
	}
	/*加密*/
	encry(acc,sizeof(Acc));
	write(fd_delete,acc,sizeof(Acc));
	close(fd_delete);
	return 0;
}
/*修改密码*/
int user_modify(Mod* mod)
{
	char filename[20] = {};
	Acc accsave = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",mod->id);
	/*以读写权限打开*/
	int fd = open(filename,O_RDWR);
	if(0 > fd)
	{
		printf("文件打开失败\n");
		return -1;
	}
	/*读入该文件信息,并解密*/
	read(fd,&accsave,sizeof(Acc));
	encry(&accsave,sizeof(Acc));
	/*对比旧密码*/
	if(0 != strcmp(accsave.password,mod->password_old))
	{
		printf("旧密码不同\n");
		return -1;
	}
	/*将新密码覆盖写入文件*/
	strcpy(accsave.password,mod->password_new);
	/*加密*/
	encry(&accsave,sizeof(Acc));
	lseek(fd,0,SEEK_SET);
	write(fd,&accsave,sizeof(Acc));
	close(fd);
	return 0;
}
/*解锁*/
int user_unlock(Acc* acc)
{
	char filename[20];
	Acc accsave = {};
	/*将卡号作为输入,作为文件名*/
	sprintf(filename,"./account/%d",acc->id);
	/*以读写权限打开文件*/
	int fd = open(filename,O_RDWR);
	if(0 > fd)
	{
		printf("文件打开失败\n");
		return -1;
	}
	/*读入该文件信息,并解密*/
	read(fd,&accsave,sizeof(Acc));
	encry(&accsave,sizeof(Acc) );
	printf("输入的身份证=%s 存储的身份证=%s\n",acc->identify,accsave.identify);
	/*对比身份证信息*/
	if(0 != strcmp(accsave.identify,acc->identify))
	{
		printf("身份证错误\n");
		close(fd);
		return -1;
	}
	/*将登录次数置位3,旧密码改为新密码,加密后覆盖写入文件*/
	accsave.cnt = 3;
	strcpy(accsave.password,acc->password);
	encry(&accsave,sizeof(Acc));
	lseek(fd,0,SEEK_SET);
	write(fd,&accsave,sizeof(Acc));
	close(fd);
	return 0;
}
