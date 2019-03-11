#ifndef TELLPHONE_H
#define TELLPHONE_H
#include<stdio.h>
#include<getch.h>
#include<string.h>
#include<stdlib.h>
typedef struct Cons
{
	char name[20];
	char sex;
	char tell[12];
} Cons;
Cons cons[100];
int cons_count=0;
int _find_name(char* str);
void anykey_continue(void)
{
	puts("按任意键返回......");
	getch();
}
char get_cmd(char start,char end)
{
	while(1)
	{
		char cmd = getch();
		if(cmd >= start && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}
void show_msg(char* msg,int sec)
{
	printf("\033[01;31m%s\n\033[00m",msg);
	sleep(sec);
}
void show_cons(Cons *str)
{
	printf("%s %s %s\n",str->name,'1'==str->sex?"男":"女",str->tell);
}
void show_menu(void)
{
	system("clear");
	puts("***欢迎使用指针电话簿***");
	puts("1、添加联系人");
	puts("2、删除联系人");
	puts("3、修改联系人");
	puts("4、查询联系人");
	puts("5、显示所有联系人");
	puts("6、退出电话簿");
	puts("-----------------");
	printf("请输入指令：");
}
void add_cons(void)
{
	if(cons_count >= 100)
	{
		show_msg("电话簿已经满了，添加失败!",1);
		return;
	}
	for(int i=0; i<100; i++)
	{
		if(0 == cons[i].sex)
		{
			printf("请输入姓名：");
			gets(cons[i].name);
			if(-1 != _find_name(cons[i].name))
			{
				show_msg("不能用重名，添加失败！",1);
				return;
			}
			printf("请输入性别(1:女 2:男):");
			cons[i].sex = getch();
			printf("%c\n",cons[i].sex);
			printf("请输入联系电话：");
			gets(cons[i].tell);
			puts("添加联系人成功!\n");
			cons_count++;
			return;
		}
	}
}
int _find_name(char* str)
{
	for(int i=0; i<100; i++)
	{
		if(cons[i].sex && 0 == strcmp(cons[i].name,str))
		{
			return i;
		}
	}
	return -1;
}
int _find_tell(char* str)
{
	for(int i=0; i<100; i++)
	{
		if(cons[i].sex && 0 == strcmp(cons[i].tell,str))
		{
			return i;
		}
	}
	return -1;
}
void list_const(void)
{
	system("clear");
	for(int i=0; i<100; i++)
	{
		if(cons[i].sex)
		{
			show_cons(&cons[i]);
		}
	}
	anykey_continue();
}
void del_cons(void)
{
	printf("请输入姓名或手机号:");
	char key[20];
	gets(key);
	int index = _find_name(key);
	if(-1 != index)
	{
		cons[index].sex = 0;
		show_msg("删除联系成功!",1);
		return;
	}
	index = _find_tell(key);
	if(-1 != index)
	{
		cons[index].sex = 0;
		show_msg("删除联系成功!",1);
		return;
	}
	show_msg("查无此人!",1);
	return;
}
void change_cons(void)
{
	printf("请输入要修改人的名字：");
	char new_name[20];
	gets(new_name);
	int index=_find_name(new_name);
	if(-1==index)
	{
		show_msg("查无此人!",1);
		return;	
	}
	else
	{
		printf("修改名字请按1，修改性别请按2，修改电话号码请按3:");
		switch(get_cmd('1','3'))
		{		
			case '1': printf("请输入修改后的姓名：");
						gets(cons[index].name);
							;break;
			case '2': printf("请输入修改后的性别(1:女 2:男):");
						cons[index].sex = getch();
							;break;
			case '3': printf("请输入修改后的联系电话：");
						gets(cons[index].tell);
							; break;
		}
	}
	show_msg("修改成功！！！",1);
	return;
	
}

void find_cons(void)
{
	int arr[10]={};
	printf("请输入有效信息:");
	char new_name[20];
	gets(new_name);
	int count=0;
	for(int i=0;i<100;i++)
	{
		if(cons[i].sex && NULL != strstr(cons[i].name,new_name))
		{
			arr[count++]=i;
		}
	}
	if (count==0)
	{
		show_msg("有效信息太少查不到！！！",1);
		return;
	}
	else
	{
		for(int i=0;i<count;i++)
		{
			show_cons(&cons[arr[i]]);
		}
	}
	anykey_continue();
	return;
}
#endif
