#include"teacher_info.h"
#include<stdlib.h>
#include"tool.h"
#include<string.h>
#include "struct.h"

void add_student(void)
{
	system("clear");
	if(stu_count!=0)
	{
	stu[stu_count].num=stu[stu_count-1].num+1;
	}
	puts("请输入姓名");
	gets(stu[stu_count].name);
	puts("请输入年龄");	
	gets(stu[stu_count].age);
	puts("请输入性别");
	scanf("%c",&stu[stu_count].sex);
	puts("添加学生信息成功");
	strcpy(stu[stu_count].password,"000000");
	getchar();
	stu_count++;
	anykey_continue();

}
void del_student(void)
{
	char str[20]={};
	
	system("clear");
	printf("请输入要删除的学生的姓名或学号\n");
	gets(str);
	for(int j=0;j<stu_count;j++)
	{
		char str1[20]={};
		sprintf(str1,"%d",stu[j].num);
		if((strcmp(stu[j].name,str)==0 || strcmp(str1,str)==0) && stu[j].index!=1)
		{
			stu[j].index=1;
			stu[j].chinese=0;
			stu[j].math=0;
			stu[j].english=0;
			printf("已删除此人\n");
			anykey_continue();
			return;
		}
	}
	printf("没有此人\n");
	anykey_continue();
}
void change_student(void)
{
	char name_new[10]={};
	char sex_new;
	char age_new[10]={};
	system("clear");
	printf("请输入要修改的学生的姓名或学号\n");
	char str[20]={};
	gets(str);
	for(int i=0;i<stu_count;i++)
	{
		char num[10]={};
		sprintf(num,"%d",stu[i].num);
		if((strcmp(stu[i].name,str)==0 || strcmp(num,str)==0) && stu[i].index!=1)
		{
			puts("请输入姓名");
			gets(name_new);
			puts("请输入年龄");	
			gets(age_new);
			puts("请输入性别");
			scanf("%c",&sex_new);
			strcpy(stu[i].name,name_new);
			strcpy(stu[i].age,age_new);
			stu[i].sex=sex_new;
			puts("修改学生信息成功");
			getchar();
			anykey_continue();
			return ;
		}
		
	}
	printf("没有此人\n");
	anykey_continue();
}
void view_on_student(void)
{
	system("clear");
	for(int i=0;i<stu_count;i++)
	{
		if(stu[i].index==0)
		{
			printf("姓名：%s 学号：%.8d\n",stu[i].name,stu[i].num);
		}
	}
	anykey_continue();
}
void view_off_student(void)
{
	system("clear");
	for(int i=0;i<stu_count;i++)
	{
		if(stu[i].index==1)
		{
			printf("姓名：%s 学号：%.8d\n",stu[i].name,stu[i].num);
		}
	}
	anykey_continue();
}
void find_student(void)
{
	system("clear");
	printf("请输入你要查找的学生的学号或姓名：\n");
	char str[20]={};
	gets(str);
	for(int i=0;i<stu_count;i++)
	{
		char num[10]={};
		sprintf(num,"%d",stu[i].num);
		if((strcmp(stu[i].name,str)==0 || strcmp(num,str)==0) && stu[i].index!=1)
		{
			printf("姓名%s 学号%d\n",stu[i].name,stu[i].num);
			anykey_continue();
			return ;
		}
		
	}
	anykey_continue();
		
}
void reset_student(void)
{
	system("clear");
	printf("请输入你要重置的学生的学号或姓名：\n");
	char str[20]={};
	gets(str);
	for(int i=0;i<stu_count;i++)
	{
		char num[10]={};
		sprintf(num,"%d",stu[i].num);
		if((strcmp(stu[i].name,str)==0 || strcmp(num,str)==0) && stu[i].index!=1)
		{
			strcpy(stu[i].password,"123456");
			puts("重置成功");
			anykey_continue();
			return ;
		}
		
	}
	anykey_continue();
}
void unlock_student(void)
{
	system("clear");
	printf("请输入你要解锁的学生的学号或姓名：\n");
	char str[20]={};
	gets(str);
	for(int i=0;i<stu_count;i++)
	{
		char num[10]={};
		sprintf(num,"%d",stu[i].num);
		if((strcmp(stu[i].name,str)==0 || strcmp(num,str)==0) && stu[i].index!=1)
		{
			stu[i].lock=0;
			puts("解锁成功");
			anykey_continue();
			return ;
		}
		
	}
	anykey_continue();
}

void batch_add_student(void)
{
	system("clear");
	FILE *frp=fopen("batch_stu.txt","r");
	if(NULL==frp)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(frp))
	{
		fscanf(frp,"%d %s %s %c %s %d %d %d %f %d %d %d %d %d %d %d\n",&stu[stu_count].num,stu[stu_count].password,stu[stu_count].name,&stu[stu_count].sex,stu[stu_count].age,&stu[stu_count].chinese,&stu[stu_count].math,&stu[stu_count].english,&stu[stu_count].avg,&stu[stu_count].sum,&stu[stu_count].rank_all,&stu[stu_count].rank_chinese,&stu[stu_count].rank_math,&stu[stu_count].rank_english,&stu[stu_count].index,&stu[stu_count].lock);
		stu_count++;
	}
	fclose(frp);
	frp=NULL;
	puts("导入成功");
	anykey_continue();
}







