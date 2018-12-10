#ifndef STRUCT_H
#define STRUCT_H

#define super_password asd
#define SUM_SEC 365*24*3600UL
#include<getch.h>
#include<stdlib.h>
#include<time.h>

typedef struct student
{
	int  num;
	char password[10];
	char name[20];
	char sex;
	char age[10];
	int chinese;
	int math;
	int english;
	float avg;
	int sum;
	int rank_all;
	int rank_chinese;
	int rank_math;
	int rank_english;
	int index;
	int lock;
}student;

typedef struct teacher 
{
	int job_num;
	char password[10];
	char name[20];
	char sex;
	char age[10];
	int work_year;
	int lock;
	int index;
}teacher;

typedef struct manager
{
	char name[20];
	char password[10];
	int ma_num;
	int lock;
	int index;
}manager;


int stu_count;
int tea_count;
int ma_count;
	
manager ma[100];
student stu[200];
teacher tea[100];



#endif//STRUCT_H





