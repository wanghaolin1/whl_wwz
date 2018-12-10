#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getch.h>
#include "struct.h"
#include "tool.h"
//学生操作函数
//显示自己基本信息
void find_news(int* str)
{    
     int i=* str;
	 system("clear");
     printf("姓名%s 学号%.8d 性别%c 年龄%s 语文:%d 数学:%d 英语:%d 平均分:%f 总分:%d\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].chinese,stu[i].math,stu[i].english,stu[i].avg,stu[i].sum);
	 anykey_continue();

}


//列出自己所有成绩排名
void find_all_rank(int* str)
{
	int i=* str;
    system("clear");
	puts("总分排名为：");
	printf("%d\n",stu[i].rank_all);
	anykey_continue();
}


//显示每科成绩排名
void find_one_rank(int* str)
{
		 int i=*str;
         system("clear");
		 puts("单科排名为：");
       	 printf("语文：第%d名\n",stu[i].rank_chinese);
         printf("数学：第%d名\n",stu[i].rank_math);
		 printf("英语：第%d名\n",stu[i].rank_english);
		 anykey_continue();

}

//修改自己登录密码
void change_stu_password(int* str)
{
  	char new[10]={};
	system("clear");
	printf("请修改您的密码\n");
	hide(new);
	strcpy(stu[*str].password,new);
	printf("修改成功\n");
	anykey_continue();
  
}
