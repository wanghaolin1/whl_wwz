#include"manager.h"
#include"tool.h"
#include<stdlib.h>
#include <string.h>
#include "struct.h"

//管理员选项函数
//增加老师
void add_teacher(void)
{
	system("clear");
	if(tea_count!=0)
	{
	tea[tea_count].job_num=tea[tea_count-1].job_num+1;
	}
	puts("请输入新教工姓名");
	gets(tea[tea_count].name);
	puts("性别：");
	scanf("%c",&tea[tea_count].sex);
	getchar();
	puts("年龄：");
	gets(tea[tea_count].age);
	puts("工龄：");
	scanf("%d",&tea[tea_count].work_year);
	getch();
	puts("添加教职工信息成功！");
	strcpy(tea[tea_count].password,"000000");
	tea_count++;
	anykey_continue();
}

//删除老师
void del_teacher(void)
{
	system("clear");
	char str[20];
	char str1[20];
	puts("请输入要删除的老师姓名或者工号:");
	gets(str);
	for(int i = 0;i<tea_count;i++)
	{
		sprintf(str1,"%d",tea[i].job_num);
		if(0 == strcmp(str,tea[i].name) || 0 == strcmp(str,str1) && 1 != tea[i].index)
		{
			tea[i].index = 1;
			puts("删除老师成功！");
			anykey_continue();
			return;
		}
	}
	puts("教师姓名或工号输入错误！");
	anykey_continue();
}	

//修改老师信息
void change_teacher(void)
{
	system("clear");
	char str[20];
	char str1[20];
	puts("请输入待修改的老师姓名或工号：");
	gets(str);
	for(int i = 0;i<tea_count;i++)
	{
		sprintf(str1,"%d",tea[i].job_num);
		if(0 == strcmp(str,tea[i].name) || 0 == strcmp(str,str1) && 1 != tea[i].index)
		{
			puts("姓名");
			scanf("%s",tea[i].name);
			getchar();
			puts("性别：");
			scanf("%c",&tea[i].sex);
			puts("年龄：");
			scanf("%s",tea[i].age);
			puts("工龄：");
			scanf("%d",&tea[i].work_year);
			puts("修改信息成功！");
			anykey_continue();
			return;
		}
		
	}
	printf("没有此人\n");
	anykey_continue();
}

//重置老师密码
void reset_teacher(void)
{
	system("clear");
	char str[20];
	char str1[20];
	puts("请输入要重置的教师姓名或者工号");
	gets(str);
	for(int i = 0;i<tea_count;i++)
	{
		sprintf(str1,"%d",tea[i].job_num);
		if(0 == strcmp(str,tea[i].name) || 0 == strcmp(str,str1) && 1!= tea[i].index)
		{
			strcpy(tea[i].password,"123456");
			puts("重置密码成功！");	
			anykey_continue();
			return;
		}
	}
	puts("教师姓名或工号输入错误！");
	anykey_continue();
}

//解锁老师
void unlock_teacher(void)
{
	system("clear");
	char str[20];
	char str1[20];
	puts("请输入要解锁的老师姓名或者工号");
	gets(str);
	for(int i = 0;i<tea_count;i++)
	{
		sprintf(str1,"%d",tea[i].job_num);
		if(0 == strcmp(str,tea[i].name) || 0 == strcmp(str,str1) && 1!= tea[i].index)
		{
			tea[i].index = 0;
			puts("解锁该教职工账号成功！");
			anykey_continue();
			return;
		}	
	}
	puts("输入教师名或工号错误！");
	anykey_continue();
}

//查找老师
void find_teacher(void)
{
	system("clear");
	puts("请输入要查找的老师姓名或者工号");
	char str[20];
	char str1[20];
	gets(str);
	for(int i = 0;i<tea_count;i++)
	{
		sprintf(str1,"%d",tea[i].job_num);
		if(((0 == strcmp(str,tea[i].name)) || (0 == strcmp(str,str1))) && 1!= tea[i].index)
		{
			printf("姓名：%s\n",tea[i].name);
			printf("工号：%.6d\n",tea[i].job_num);
			printf("性别：%c\n",tea[i].sex);
			printf("年龄：%s\n",tea[i].age);
			printf("工龄：%d\n",tea[i].work_year);
			anykey_continue();
			return;
		}
	}
	puts("输入的老师名字错误或者该学校系统没有这个老师!");
	puts("请重新输入");
	anykey_continue();
}

//显示在职老师
void view_on_teacher(void)
{
	system("clear");
	for(int i =0;i<tea_count;i++)
	{
		if(tea[i].index == 0  )
		{
			printf("姓名：%s ",tea[i].name);
			printf("工号：%.6d ",tea[i].job_num);
			printf("性别：%c ",tea[i].sex);
			printf("年龄：%s ",tea[i].age);
			printf("工龄：%d ",tea[i].work_year);
			printf("\n");
		}
	}
	anykey_continue();
}

//显示离职老师
void view_off_teacher(void)
{
	system("clear");
	for(int i = 0;i<tea_count;i++)
	{
		if( 1 == tea[i].index)
		{
			printf("姓名：%s ",tea[i].name);
			printf("工号：%.6d ",tea[i].job_num);
			printf("性别：%c ",tea[i].sex);
			printf("年龄：%s ",tea[i].age);
			printf("工龄：%d ",tea[i].work_year);
			printf("\n");
		}
	}
	anykey_continue();
}


//修改自己登录密码
void change_password(int *m)
{
	char new[10]={};
	system("clear");
	printf("请修改您的密码\n");
	hide(new);
	strcpy(ma[*m].password,new);
	printf("修改成功\n");
	anykey_continue();
}

void batch_add_teacher(void)
{
	system("clear");
	FILE *frp=fopen("batch_tea.txt","r");
	if(NULL==frp)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(frp))
	{
		fscanf(frp,"%d %s %s %c %s %d %d %d\n",&tea[tea_count].job_num,tea[tea_count].password,tea[tea_count].name,&tea[tea_count].sex,tea[tea_count].age,&tea[tea_count].work_year,&tea[tea_count].lock,&tea[tea_count].index);
		tea_count++;
	}
	fclose(frp);
	frp=NULL;
	puts("导入成功");
	anykey_continue();
}





