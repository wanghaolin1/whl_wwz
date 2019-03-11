#include "all.h"



int main()
{
	//创建链表
	StuList* stulist = create_list_stu();
	TeaList* tealist = create_list_tea();
	//读文件标志位
	bool flag2 = true;
	bool flag1 = true;
	while(1)
	{
		show_first_menu();
		int key = get_first_key();
		if(1 == key)
		{
			key = login_menu(stulist,tealist,1);
			if(key)
			{
				flag1 && read_tea(tealist);
				flag1 = false;
				show_admini_menu(stulist,tealist);
				write_tea(tealist);
			}
		}
		else if(2 == key)
		{
			key = login_menu(stulist,tealist,2);
			if(key > 0)
			{
				//读学生文件
				flag2 && read_stu(stulist);
				flag2 = false;
				show_teacher_menu(stulist,tealist,key);
				write_stu(stulist);
			}		
		}	
	}
	
}
