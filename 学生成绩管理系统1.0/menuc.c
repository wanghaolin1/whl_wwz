#include"admin.h"
#include"menuc.h"
#include<string.h>
#include"tool.h"
#include "struct.h"
#include "student.h"
#include"teacher.h"
#include"manager.h"
#include"supermanager.h"
#include "teacher_info.h"
#include "teacher_score.h"
#include<stdio.h>
//主界面
void major_menu(void)
{
	system("clear");
	puts("***欢迎进入本校系统***");
	puts("***请选择登录入口***");
	puts("1、管理员登录");
	puts("2、老师登录");
	puts("3、学生登录");
	puts("0、保存退出");
	puts("-------------------");
	puts("请输入登录方式：");
	
}	


//学生登录页面
void student_menu(void)
{
	system("clear");
	puts("1、查询学生信息");
	puts("2、查询总分排名");
	puts("3、查看单科排名");
	puts("4、修改登录密码");
	puts("0、退出");
	printf("请输入：");
}
//老师登录页面菜单
void teacher_menu(void)
{
	system("clear");
	puts("***请选择管理方式***");
	puts("1、学生信息管理");
	puts("2、学生成绩管理");
	puts("3、修改登录密码");
	puts("0、退出");
	printf("请输入：");
}
//学生信息管理系统
void teacher_info_menu(void)
{
	system("clear");
	puts("***学生信息管理系统***");
	puts("1、添加新学生信息");
	puts("2、删除学生");
	puts("3、修改学生信息");
	puts("4、显示全部学生");
	puts("5、显示退学学生");
	puts("6、查询学生");
	puts("7、重置学生密码");
	puts("8、解锁学生账号");	
	puts("0、退出");
	printf("请输入：");
}
//学生成绩管理系统
void teacher_score_menu(void)
{
	system("clear");
	puts("***学生成绩管理系统***");
	puts("1、录入学生成绩");
	puts("2、修改学生成绩");
	puts("3、查询学生成绩");
	puts("4、排序");
	puts("0、退出");
	printf("请输入:");
	
}
//管理员登录菜单
void manager_menu(void)
{
	system("clear");
	puts("***管理员系统***");
	puts("1、添加老师");
	puts("2、删除老师");
	puts("3、修改老师信息");
	puts("4、重置老师密码");
	puts("5、解锁老师账号");
	puts("6、查询老师");
	puts("7、显示在职老师");
	puts("8、显示离职老师");
	puts("9、修改登录密码");
	puts("0、退出");
	printf("请输入：");
}

//超级管理员菜单
void super_manager_menu(void)
{
	system("clear");
	puts("***超级管理员***");
	puts("1、添加管理员");
	puts("2、删除管理员");
	puts("3、重置管理员密码");
	puts("4、解锁管理员账号");
	puts("5、显示所有管理员");
	puts("0、退出");
	printf("请输入：");
}

//添加老师菜单
void add_teacher_menu(void)
{
	system("clear");
	puts("1、单个添加");
	puts("2、批量导入");
	puts("0、退出");
	printf("请输入：");
}

//添加学生菜单
void add_student_menu(void)
{
	system("clear");
	puts("1、单个添加");
	puts("2、批量导入");
	puts("0、退出");
	printf("请输入：");
}

//录入分数菜单
void input_score_menu(void)
{
	system("clear");
	puts("1、单个录入");
	puts("2、批量导入");
	puts("0、退出");
	printf("请输入：");
}

void rank_menu(void)
{
	system("clear");
	puts("1、显示总分排序");
	puts("2、显示语文单科排序");
	puts("3、显示数学单科排序");
	puts("4、显示英语单科排序");
	puts("0、退出");
	printf("请输入：");
}

