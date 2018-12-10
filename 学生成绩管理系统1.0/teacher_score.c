#include"teacher_score.h"
#include<stdlib.h>
#include"tool.h"
#include<string.h>
#include "struct.h"

void add_score(void)
{
	int chinese_new;
	int math_new;
	int english_new;
	system("clear");
	printf("请输入要录入成绩的学生的姓名或学号\n");
	char str[20]={};
	gets(str);
	for(int i=0;i<stu_count;i++)
	{
		char num[10]={};
		sprintf(num,"%d",stu[i].num);
		if((strcmp(stu[i].name,str)==0 || strcmp(num,str)==0) && stu[i].index!=1)
		{
			printf("请输入此人的语文成绩、数学成绩、英语成绩\n");
			scanf("%d",&chinese_new);
			stu[i].chinese=chinese_new;
			scanf("%d",&math_new);
			stu[i].math=math_new;
			scanf("%d",&english_new);
			stu[i].english=english_new;
			getchar();
			anykey_continue();
			return ;
		}
		
	}
	printf("没有此人\n");
	anykey_continue();
}
void change_score(void)
{
	
	int chinese_new;
	int math_new;
	int english_new;
	system("clear");
	printf("请输入要修改的学生的姓名或学号\n");
	char str[20]={};
	gets(str);
	char num[10]={};
	for(int i=0;i<stu_count;i++)
	{
		sprintf(num,"%d",stu[i].num);
		if((strcmp(stu[i].name,str)==0 || strcmp(num,str)==0) && stu[i].index!=1)
		{
			printf("请输入要修改的语文成绩、数学成绩、英语成绩\n");
			scanf("%d",&chinese_new);
			stu[i].chinese=chinese_new;
			scanf("%d",&math_new);
			stu[i].math=math_new;
			scanf("%d",&english_new);
			stu[i].english=english_new;
			getchar();
			anykey_continue();
			return ;
		}
		
	}
	printf("没有此人\n");
	anykey_continue();
}
void find_score(void)
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
			printf("语文成绩%d 数学成绩%d 英语成绩%d\n",stu[i].chinese,stu[i].math,stu[i].english);
			anykey_continue();
			return ;
		}
		
	}
	anykey_continue();
}
void rank_score(void)
{
	for(int i=0;i<stu_count;i++)
	{
		stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;
		stu[i].avg=stu[i].sum/3;
	}
	for(int i=0;i<stu_count;i++)
	{
		stu[i].rank_all=stu_count;
		stu[i].rank_chinese=stu_count;
		stu[i].rank_math=stu_count;
		stu[i].rank_english=stu_count;
		for(int j=0;j<stu_count;j++)
		{
			if(stu[i].sum>=stu[j].sum && stu[i].num!=stu[j].num)
			{
				stu[i].rank_all--;
			}
			if(stu[i].chinese>=stu[j].chinese && stu[i].num!=stu[j].num)
			{
				stu[i].rank_chinese--;
			}
			if(stu[i].math>=stu[j].math && stu[i].num!=stu[j].num)
			{
				stu[i].rank_math--;
			}
			if(stu[i].english>=stu[j].english && stu[i].num!=stu[j].num)
			{
				stu[i].rank_english--;
			}
		}
		
	}
}

void rank_all(void)
{
	for(int i=0;i<stu_count;i++)
	{
		for(int j=0;j<stu_count;j++)
		{
			if(i+1==stu[j].rank_all && stu[j].index==0)
			{
				printf("姓名：%s 学号：%.8d 分数：%d 名次：%d\n",stu[j].name,stu[j].num,stu[j].sum,i+1);
			}
		}
	}
	anykey_continue();
}
void rank_chinese(void)
{
	for(int i=0;i<stu_count;i++)
	{
		for(int j=0;j<stu_count;j++)
		{
			if(i+1==stu[j].rank_chinese && stu[j].index==0)
			{
				printf("姓名：%s 学号：%.8d 分数：%d 名次：%d\n",stu[j].name,stu[j].num,stu[j].chinese,i+1);
			}
		}
	}
	anykey_continue();
}
void rank_math(void)
{
	for(int i=0;i<stu_count;i++)
	{
		for(int j=0;j<stu_count;j++)
		{
			if(i+1==stu[j].rank_math && stu[j].index==0)
			{
				printf("姓名：%s 学号：%.8d 分数：%d 名次：%d\n",stu[j].name,stu[j].num,stu[j].math,i+1);
			}
		}
	}
	anykey_continue();
}
void rank_english(void)
{
	for(int i=0;i<stu_count;i++)
	{
		for(int j=0;j<stu_count;j++)
		{
			if(i+1==stu[j].rank_english && stu[j].index==0)
			{
				printf("姓名：%s 学号：%.8d 分数：%d 名次：%d\n",stu[j].name,stu[j].num,stu[j].english,i+1);
			}
		}
	}
	anykey_continue();
}


void batch_add_score(void)
{
	int i;
	system("clear");
	FILE *frp=fopen("batch_score.txt","r");
	if(NULL==frp)
	{
		printf("打开文件失败\n");
		return;
	}
	for(i=0;stu[i].num!=15918150;i++);
	stu_count=i;
	while(!feof(frp))
	{
		fscanf(frp,"%d %d %d\n",&stu[stu_count].chinese,&stu[stu_count].math,&stu[stu_count].english);
		stu_count++;
	}
	fclose(frp);
	frp=NULL;
	puts("导入成功");
	anykey_continue();
}









