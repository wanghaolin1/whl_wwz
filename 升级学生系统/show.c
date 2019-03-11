#include "all.h"
int id_stu = 1;
int id_tea = 1;



//返回教师主界面
void tea_add_menu_to_menu(StuList* list1,TeaList* list2,int id)
{
	printf("＊＊＊＊＊按任意键返回＊＊＊＊＊＊\n");
	getch();
	show_teacher_menu(list1,list2,id);
}
//返回管理员主界面
void adm_add_menu_to_menu(StuList* list1,TeaList* list2)
{
	printf("＊＊＊＊＊按任意键返回＊＊＊＊＊＊\n");
	getch();
	show_admini_menu(list1,list2);
}

//主主界面
void show_first_menu(void)
{
	system("clear");
	printf("\033[47;33m请输入指令：\033[0m");
}
//主主界面获取按键
int get_first_key(void)
{
	while(1)
	{	
		switch(getch())
		{
			case 49: return 1;
			case 50: return 2;
		}
	}
}
//显示教师界面
void show_teacher_menu(StuList* list1,TeaList* list2,int id)
{
	system("clear");
	printf("＊＊＊＊＊老师欢迎你＊＊＊＊＊\n");
	printf("1.添加学生\n");
	printf("2.删除学生\n");
	printf("3.修改学生信息\n");
	printf("4.查询学生信息\n");
	printf("5.排名学生成绩\n");
	printf("6.显示所有(测试)\n");
	printf("7.退出\n");
	get_tea_key(list1,list2,id);
}
void show_teacher_order(StuList* list1,TeaList* list2,int id)
{
	system("clear");
	printf("＊＊＊＊＊成绩排名＊＊＊＊＊\n");
	printf("1.总分排名\n");
	printf("2.语文排名\n");
	printf("3.数学排名\n");
	printf("4.英语排名\n");
	printf("5.平均分排名\n");
	printf("6.返回\n");
	get_tea_oder_key(list1,list2,id);
}
void get_tea_oder_key(StuList* list1,TeaList* list2,int id)
{
	switch(getch())
	{
		case 49:tea_order_stu(list1,list2,id,0);break;
		case 50:tea_order_stu(list1,list2,id,1);break;
		case 51:tea_order_stu(list1,list2,id,2);break;
		case 52:tea_order_stu(list1,list2,id,3);break;
		case 53:tea_order_stu(list1,list2,id,4);break;
		default:show_teacher_menu(list1,list2,id);
	}
}
//获取教师界面按键
void get_tea_key(StuList* list1,TeaList* list2,int id)
{
	switch(getch())
	{
		case 49:tea_add_stu(list1,list2,id);break;
		case 50:tea_del_stu(list1,list2,id);break;
		case 51:tea_mod_stu(list1,list2,id);break;
		case 52:tea_find_stu(list1,list2,id);break;
		case 53:show_teacher_order(list1,list2,id);break;
		case 54:show_all_stu(list1,list2,id);break;
		default:return;
	}
}
//显示管理员界面
void show_admini_menu(StuList* list1,TeaList* list2)
{
	system("clear");
	printf("＊＊＊＊＊管理员界面＊＊＊＊＊\n");
	printf("1.添加教师\n");
	printf("2.删除教师\n");
	printf("3.修改教师信息\n");
	printf("4.查看所有(测试)\n");
	printf("5.退出\n");
	get_adm_key(list1,list2);
}
//获取管理员界面按键
void get_adm_key(StuList* list1,TeaList* list2)
{
	switch(getch())
	{
		case 49:adm_add_tea(list1,list2);break;
		case 50:adm_del_tea(list1,list2);break;
		case 51:adm_mod_tea(list1,list2);break;
		case 52:show_all_tea(list1,list2);break;
		default:return;
	}
}
void show_all_tea(StuList* list1,TeaList* list2)
{
	system("clear");
	printf("工号\t姓名\t性别\t年龄\t工龄\n");
	for(Node* node=list2->head;node;node=node->next)
	{
		Tea* tea = node->data;
		printf("%d\t%s\t%s\t%d\t%d\n",tea->id,tea->name,tea->sex,tea->age,tea->ls);
	}
	printf("＊＊＊＊＊按任意键返回＊＊＊＊＊\n");
	getch();
	show_admini_menu(list1,list2);
}

