#include "all.h"

//根据id查找学生节点
Node* find_id_stu_node(StuList* list,int id)
{
	if(NULL == list) return NULL;
	Node* node = list->head;
	Stu* student = NULL;
	for(Node* n=node;n;n=n->next)
	{
		student = n->data;
		if(id == student->id)
		 return n;
	}
	return NULL;
}
//根据id查找学生编号
int find_id_stu_int(StuList* list,int id)
{
	if(NULL == list) return -1;
	Node* node = list->head;
	Stu* student = NULL;
	for(int i=0;i<list->cnt;i++)
	{
		student = node->data;
		if(id == student->id)
			return i;
		node = node->next;
	}
	return -1;
}
//根据id查找教师节点
Node* find_id_tea_node(TeaList* list,int id)
{
	if(NULL == list) return NULL;
	Node* node = list->head;
	Tea* teacher = NULL;
	for(Node* n=node;n;n=n->next)
	{
		teacher = n->data;
		if(id == teacher->id)
		 return n;
	}
	return NULL;
}
//根据id查找教师编号
int find_id_tea_int(TeaList* list,int id)
{
	if(NULL == list) return -1;
	Node* node = list->head;
	Stu* teacher = NULL;
	for(int i=0;i<list->cnt;i++)
	{
		teacher = node->data;
		if(id == teacher->id)
			return i;
		node = node->next;
	}
	return -1;
}
//计算年龄
int age_year(int year)
{
	return time(NULL)/(365*24*60*60)+1970-year;
}
//隐藏密码
char* put_pw(char* pw)
{
	for(int i=0; i<20; i++)
	{
		stdin->_IO_read_ptr=stdin->_IO_read_end;
		pw[i]=getch();
		if(pw[i] == 127)
		{
			if(i>0)
			{
				i -= 2;
				printf("\b \b");
			}
			else
			{
				i--;
			}
		}
		else if(pw[i] == 10)
		{
			pw[i]='\0';
			break;
		}
		else
		{
			putchar('*');
		}
	}
	return pw;
}
int login_menu(StuList* list2,TeaList* list1,char num)
{
	int idid = 0;
	
	system("clear");
	if(2 == num)
	{
		
		int count = 0;
		printf("＊＊＊＊＊教师登录界面＊＊＊＊＊\n");
		while(1)
		{
			
			printf("用户名:");
			scanf("%d",&idid);
			getchar();
			if(-1  == find_id_tea_int(list1,idid))
			{
				printf("用户名不存在！\n");
				usleep(800000);
				if(count >= 2)	
					break;
				else
					count++;
			}
			else
			{
				Tea* teacher = find_id_tea_node(list1,idid)->data;
				if(0 == teacher->back)
				{
					printf("此教师已被退学，无法登录！\n");
					usleep(800000);
					break;
				}
				else
				{
					while(1)
					{
						if(teacher->flag >= 3)
						{
							printf("此教师账号已被锁定！\n");
							usleep(800000);
							system("clear");
							return -1;
						}
						else
						{
							char pw[20];
							printf("密码：");
							put_pw(pw);	
							if(strcmp(pw,teacher->pw) != 0) //比较
							{
								teacher->flag++;
								printf("\n密码错误！\n");
								usleep(800000);
								system("clear");
							}
							else
							{
								//show_teacher_menu(list2,list1,idid);
								return idid;
							}
						}
					}
				}	
			}
		
		}
	}
	else
	{
		printf("＊＊＊＊＊管理员界面＊＊＊＊＊\n");
		int key = 0;
		printf("请输入密钥：");
		char pw[20];
		put_pw(pw);
		
		if(0 == strcmp(pw,"123"))
		{
			//show_admini_menu(list2,list1);
			return 1;
		}
		else
		{	
			printf("\n我要报警了！\n");
			usleep(800000);
		}
		
	}
	return 0;
}
void swap(Node* node1,Node* node2)
{
	void* temp=node1->data;
	node1->data=node2->data;
	node2->data=temp;
}

