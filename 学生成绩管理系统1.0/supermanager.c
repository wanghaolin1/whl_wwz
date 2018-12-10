#include<stdio.h>
#include<string.h>
#include "struct.h"
#include"tool.h"
#include"supermanager.h"
//增加管理员

void add_manager(void)
{
	system("clear");
	if(ma_count!=0)
	{
	ma[ma_count].ma_num=ma[ma_count-1].ma_num+1;
	}
	strcpy(ma[ma_count].password,"000000");
	puts("请输入姓名");
	gets(ma[ma_count].name);
	puts("添加管理员信息成功");
	ma_count++;
	anykey_continue();
}	
void del_manager(void)
{	
	char str[20]={};
	system("clear");
	printf("请输入要删除的管理员的姓名\n");
	gets(str);
	for(int j=0;j<ma_count;j++)
	{
		if(strcmp(ma[j].name,str)==0 && ma[j].index!=1)
		{
			ma[j].index=1;
			printf("已删除此人\n");
			anykey_continue();
			return;
		}
	}
	printf("没有此人\n");
	anykey_continue();
}	 
void reset_manager(void)
{
	system("clear");
	printf("请输入你要重置的管理员的姓名：\n");
	char str[20]={};
	gets(str);
	for(int i=0;i<ma_count;i++)
	{
		if(strcmp(ma[i].name,str)==0 && ma[i].index!=1)
		{
			strcpy(ma[i].password,"123456");
			puts("重置成功");
			anykey_continue();
			return ;
		}
		
	}
	anykey_continue();
} 
void unlock_manager(void )
{
	system("clear");
	printf("请输入你要解锁的管理员的名字：\n");
	char str[20]={};
	gets(str);
	for(int i=0;i<ma_count;i++)
	{
		if(strcmp(ma[i].name,str)==0 && ma[i].index!=1)
		{
			ma[i].lock=0;
			puts("解锁成功");
			anykey_continue();
			return ;
		}
		
	}
	anykey_continue();
}
void list_manager(void)
{
	system("clear");
	for(int i=0;i<ma_count;i++)
	{
		if(ma[i].index==0)
		{
			printf("姓名：%s 管理员工号：%.6d\n",ma[i].name,ma[i].ma_num);
		}
	}
	anykey_continue();
}  




