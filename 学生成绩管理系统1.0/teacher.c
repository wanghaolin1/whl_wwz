#include"teacher.h"
#include<stdlib.h>
#include "tool.h"
#include<string.h>
#include "struct.h"


void change_tea_password(int *str)
{
	char new[10]={};
	system("clear");
	printf("请修改您的密码\n");
	hide(new);
	strcpy(tea[*str].password,new);
	printf("修改成功\n");
	anykey_continue();
}
	
