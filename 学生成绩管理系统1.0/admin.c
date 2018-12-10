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
	

void super_admin()
{
	system("clear");
	char password[10]={};
	printf("请输入超级管理员密钥：\n");
	hide(password);
	if(strcmp("asd",password)==0)		
	{
		while(1)
		{
			super_manager_menu();
			switch(get_cmd('0','5'))
			{
				case '1': add_manager(); 	 break;
				case '2': del_manager();	 break;
				case '3': reset_manager(); break;
				case '4': unlock_manager();break;
				case '5': list_manager();  break;
				case '0': return ;
			}
		}
	}
	else
	{
		return ;
	}
}
void manager_admin()
{
	system("clear");
	char password[10]={};
	char name[20]={};
	int count=0;
	printf("请输入您的用户名：");
	gets(name);
	for(int i=0;i<ma_count;i++)
	{
		if(strcmp(name,ma[i].name)==0  && ma[i].lock == 1)
		{
			printf("你的账户已被锁定，请联系超级管理员\n");
			anykey_continue();
			return;
		}
		if(strcmp(name,ma[i].name)==0 && ma[i].lock == 0 && ma[i].index==1)
		{
			printf("此人已经离职\n");
			anykey_continue();
			return;
		}
		if(strcmp(name,ma[i].name)==0 && ma[i].lock == 0 && ma[i].index==0)
		{
			while(count < 3)
			{
		 		printf("请输入密码\n");
				hide(password);
				if(strcmp(password,ma[i].password)==0)
				{	
					if(strcmp(password,"000000")==0)
					{
						char new[10]={};
						system("clear");
						printf("请修改您的密码\n");
						hide(new);
						strcpy(ma[i].password,new);
						printf("修改成功\n");
						getchar();
					}			
					while(1)
					{
						manager_menu();
						switch(get_cmd('0','9'))
						{
							case '1': add_tea(); 	 break;
							case '2': del_teacher();	 break;
							case '3': change_teacher(); break;
							case '4': reset_teacher(); 	 break;
							case '5': unlock_teacher();  break;
							case '6': find_teacher();break;
							case '7': view_on_teacher();break;
							case '8': view_off_teacher();break;
							case '9': change_password(&i);break;
							case '0':return ;
						}
					}
				}
				else
		 		{
					printf("您的密码错误\n");
					count++;
				}
			}
			ma[i].lock=1;
			printf("你的账户已被锁定，请联系超级管理员\n");
			getch();
			anykey_continue();
			return ;
		}
	}	
}
void teacher_admin()
{
	system("clear");
	char password[10]={};
	char name[20]={};
	int count=0;
	printf("请输入您的用户名：");
	gets(name);
	for(int i=0;i<tea_count;i++)
	{
		if(strcmp(name,tea[i].name)==0  && tea[i].lock == 1)
		{
			printf("你的账户已被锁定，请联系管理员\n");
			anykey_continue();
			return;
		}
		if(strcmp(name,tea[i].name)==0 && tea[i].lock == 0 && tea[i].index==1)
		{
			printf("此人已经离职\n");
			anykey_continue();
			return;
		}
		if(strcmp(name,tea[i].name)==0 && tea[i].lock == 0 && tea[i].index==0)
		{
			while(count < 3)
			{
		 		printf("请输入密码\n");
				hide(password);
				if(strcmp(password,tea[i].password)==0)
				{	
					if(strcmp(password,"000000")==0)
					{
						char new[10]={};
						system("clear");
						printf("请修改您的密码\n");
						hide(new);
						strcpy(tea[i].password,new);
						printf("修改成功\n");
						getchar();
					}			
					while(1)
					{
						teacher_menu();
						switch(get_cmd('0','3'))
						{
								case '1': teacher_admin_info();break;
								case '2': teacher_admin_score();break;
								case '3': change_tea_password(&i);break;
								case '0':return ;
						}
					}
				}
				else
		 		{
					printf("您的密码错误\n");
					count++;
				}
			}
			tea[i].lock=1;
			printf("你的账户已被锁定，请联系管理员\n");
			getch();
			anykey_continue();
			return ;
		}
	}	
}
void student_admin()
{
	system("clear");
	char password[10]={};
	char name[20]={};
	int count=0;
	printf("请输入您的用户名：");
	gets(name);
	for(int i=0;i<stu_count;i++)
	{
		if(strcmp(name,stu[i].name)==0  && stu[i].lock == 1)
		{
			printf("你的账户已被锁定，请联系超级管理员\n");
			anykey_continue();
			return;
		}
		if(strcmp(name,stu[i].name)==0 && stu[i].lock == 0 && stu[i].index==1)
		{
			printf("此人已经退学\n");
			anykey_continue();
			return;
		}
		if(strcmp(name,stu[i].name)==0 && stu[i].lock == 0 && stu[i].index==0)
		{
			while(count < 3)
			{
		 		printf("请输入密码\n");
				hide(password);
				if(strcmp(password,stu[i].password)==0)
				{	
					if(strcmp(password,"000000")==0)
					{
						char new[10]={};
						system("clear");
						printf("请修改您的密码\n");
						hide(new);
						strcpy(stu[i].password,new);
						printf("修改成功\n");
						getchar();
					}			
					while(1)
					{
						student_menu();
						switch(get_cmd('0','4'))
						{
							case '1': find_news(&i); break;
							case '2': find_all_rank(&i);break;
							case '3': find_one_rank(&i);break;
							case '4': change_stu_password(&i); break;
							case '0':return ;
						}
					}
				}
				else
		 		{
					printf("您的密码错误\n");
					count++;
				}
			}
			stu[i].lock=1;
			printf("你的账户已被锁定，请联系老师\n");
			getch();
			anykey_continue();
			return ;
		}
	}	
}


void teacher_admin_info()
{
	while(1)
	{
		teacher_info_menu();
		switch(get_cmd('0','8'))
		{
			case '1':add_stu();break;
			case '2':del_student();break;
			case '3':change_student();break;
			case '4':view_on_student();break;
			case '5':view_off_student();break;
			case '6':find_student();break;
			case '7':reset_student();break;
			case '8':unlock_student();break;
			case '0':return;
		}
	}

}


void teacher_admin_score()
{
	while(1)
	{
		teacher_score_menu();
		switch(get_cmd('0','4'))
		{
			case '1':input_score();break;
			case '2':change_score();break;
			case '3':find_score();break;
			case '4':show_rank();break;
			case '0':return;
			
		}
	}
}

void add_stu(void)
{
	while(1)
	{
		add_teacher_menu();
		switch(get_cmd('0','2'))
		{
			case '1':add_student();break;
			case '2':batch_add_student();break;
			case '0':return;
		}
	}
}

void add_tea(void)
{
	while(1)
	{
		add_teacher_menu();
		switch(get_cmd('0','2'))
		{
			case '1':add_teacher();break;
			case '2':batch_add_teacher();break;
			case '0':return;
		}
	}
}

void input_score(void)
{
	while(1)
	{
		input_score_menu();
		switch(get_cmd('0','2'))
		{
			case '1':add_score();break;
			case '2':batch_add_score();break;
			case '0':return;
		}
	}
}

void show_rank(void)
{
	rank_score();
	while(1)
	{
		rank_menu();
		switch(get_cmd('0','4'))
		{
			case '1':rank_all();break;
			case '2':rank_chinese();break;
			case '3':rank_math();break;
			case '4':rank_english();break;
			case '0':return;
	  	}
	}
}











