#include "all.h"



//增删改
void adm_add_tea(StuList* list1,TeaList* list2)
{
	system("clear");
	printf("＊＊＊＊＊添加教师＊＊＊＊＊\n");
	Tea* tea = malloc(sizeof(Tea));
	char sex[10]={};
	printf("请输入姓名：");
	gets(tea->name);//1
	while(1)
	{
		printf("请输入性别：");
		gets(sex);
		if(0 == strcmp(sex,"男")|| 0 == strcmp(sex,"女"))
			break;
		else
		{
			printf("输入错误！\n");
		}
	}
	printf("请输入出生年份：");
	scanf("%d",&tea->year);//3
	getchar();
	printf("请输入入职年份：");//4
	scanf("%d",&tea->work);
	getchar();
	
	//工号，密码性别年龄，出生年份，入职年份，工龄flag,back
	tea->id = id_tea++;//5
	strcpy(tea->pw,"123");//6
	strcpy(tea->sex,sex);//2
	tea->age = age_year(tea->year);//7
	tea->ls = age_year(tea->work);//8
	tea->flag = 0;//9
	tea->back = 1;//10
	addend_tail_list_tea(list2,tea);
	printf("添加成功！\n");
	adm_add_menu_to_menu(list1,list2);
}
//删除老师
void adm_del_tea(StuList* list1,TeaList* list2)
{
	system("clear");
	printf("＊＊＊＊＊删除教师＊＊＊＊＊\n");
	int num = 0;
	printf("请输入教师工号：");
	scanf("%d",&num);
	getchar();
	if(-1 == find_id_tea_int(list2,num))
	{
		printf("此人不存在!\n");
	}
	else
	{
		Tea* teacher = find_id_tea_node(list2,num)->data;
		if(0 == teacher->back)
		{
			printf("此教师已被辞退！\n");
		}
		else
		{
			char flag = 'a';
			printf("你确定要删除工号为%d的教师吗？(y/n)\n",teacher->id);
			scanf("%c",&flag);
			getchar();
			if('y' == flag)
			{
				teacher->back = 0;
				printf("删除成功！\n");
			}
			else
				printf("没有删除！\n");
		}
	}
	adm_add_menu_to_menu(list1,list2);
}
//修改教师信息
void adm_mod_tea(StuList* list1,TeaList* list2)
{
	system("clear");
	printf("＊＊＊＊＊修改教师信息＊＊＊＊＊\n");
	
	int num = 0;
	printf("请输入工号：");
	scanf("%d",&num);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	
	if(find_id_tea_int(list2,num) == -1)
	{
		printf("此人不存在！\n");
	}
	else
	{
		Tea* teacher = find_id_tea_node(list2,num)->data;
		if(0 == teacher->back)
		{
			printf("此教师已被辞退！\n");
		}
		else
		{
			int n = 10;
			printf("需要修改姓名吗？(1/0)：");
			scanf("%d",&n);
			getchar();
			if(1 == n)
			{
				printf("请输入要修改的姓名：");
				gets(teacher ->name);
				printf("修改姓名成功！\n");
			}
			printf("需要修改性别吗？(1/0)：");
			scanf("%d",&n);
			getchar();
			if(1 == n)
			{
				printf("请输入性别：");
				gets(teacher ->sex);
				printf("修改性别成功！\n");
			}
			printf("需要修改出生年份吗？(1/0):");
			scanf("%d",&n);
			getchar();
			if(1 == n)
			{
				printf("请输入出生年份：");
				scanf("%d",&teacher ->year);
				getchar();
				teacher ->age = age_year(teacher ->year);
				printf("修改出生年份成功！\n");
			}
		}
	}
	adm_add_menu_to_menu(list1,list2);		
}
