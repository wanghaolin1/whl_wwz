#include "all.h"


void show_all_stu(StuList* list1,TeaList* list2,int id)
{
	system("clear");
	printf("学号\t姓名\t总分\t语文\t数学\t英语\t平均分\n");
	for(Node* node=list1->head;node;node=node->next)
	{
		Stu* stu = node->data;
		printf("%d\t%s\t%g\t%g\t%g\t%g\t%g\n",stu->id,stu->name,stu->sum,stu->chinese,stu->math,stu->english,stu->ave);
	}
	printf("＊＊＊＊＊按任意键返回＊＊＊＊＊\n");
	getch();
	show_teacher_menu(list1,list2,id);
}


//增加学生
void tea_add_stu(StuList* list1,TeaList* list2,int id)
{
	system("clear");
	printf("＊＊＊＊＊添加学生＊＊＊＊＊\n");
	Stu* stu = malloc(sizeof(Stu));
	
	char sex[10]={};
	
	printf("请输入姓名：");
	gets(stu->name);//姓名
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
	scanf("%d",&stu->year);
	getchar();
	
	stu->id = id_stu++;//账号	
	strcpy(stu->sex,sex);//性别
	stu->age = age_year(stu->year);//年龄
	
	srand(time(NULL));
	stu->chinese = rand()%101;//语文成绩
	stu->math = rand()%101;//数学成绩
	stu->english = rand()%101;//英语成绩
	stu->sum = stu->chinese + stu->math + stu->english;
	stu->ave = stu->sum / 3;//平均分
	stu->c_rank = 0;//语文排名
	stu->m_rank = 0;//数学排名
	stu->e_rank = 0;//英语排名
	stu->rank = 0;//总分排名
	stu->flag = 0;//密码标志位
	stu->back = 1;//退学标志位
	printf("%g %g %g %g ",stu->chinese,stu->math,stu->english,stu->sum);
	addend_tail_list_stu(list1,stu);
	printf("添加成功！\n");
	tea_add_menu_to_menu(list1,list2,id);
}
//删除学生
void tea_del_stu(StuList* list1,TeaList* list2,int id)
{
	system("clear");
	printf("＊＊＊＊＊删除学生＊＊＊＊＊\n");
	int num = 0;
	printf("请输入要删除学生的学号：");
	scanf("%d",&num);
	getchar();

	if(-1 == find_id_stu_int(list1,num))
	{
		printf("此人不存在\n");
	}
	else 
	{
		Stu* student = find_id_stu_node(list1,num)->data;
		if(0 == student->back)
		{
			printf("此人以被退学！\n");
		}
		else
		{
			printf("打印编号：%d\n",find_id_stu_int(list1,num));
			char flag = 'n';
			printf("\033[47;33m你确定要删除学号为%d的学生吗?(y/n)\033[0m\n",num);
			scanf("%c",&flag);
			getchar();
			if('y' == flag)
			{
				Stu* student = find_id_stu_node(list1,num)->data;
				student->back = 0;
				printf("删除成功！\n");
			}
			else
			{
				printf("没有删除！\n");
			}
		}
	}
	tea_add_menu_to_menu(list1,list2,id);
}
//修改学生信息
void tea_mod_stu(StuList* list1,TeaList* list2,int id)
{
	system("clear");
	printf("＊＊＊修改学生信息＊＊＊\n");
	int num = 0;
	printf("请输入学号：");
	scanf("%d",&num);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	
	if(find_id_stu_int(list1,num) == -1)
	{
		printf("此人不存在！\n");
	}
	else
	{
		Stu* student = find_id_stu_node(list1,num)->data;
		if(0 == student->back)
		{
			printf("此人已被退学！\n");
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
				gets(student->name);
				printf("修改姓名成功！\n");
			}
			printf("需要修改性别吗？(1/0)：");
			scanf("%d",&n);
			getchar();
			if(1 == n)
			{
				printf("请输入性别：");
				gets(student->sex);
				printf("修改性别成功！\n");
			}
			printf("需要修改出生年份吗？(1/0):");
			scanf("%d",&n);
			getchar();
			if(1 == n)
			{
				printf("请输入出生年份：");
				scanf("%d",&student->year);
				getchar();
				student->age = age_year(student->year);
				printf("修改出生年份成功！\n");
			}
		}
	}
	tea_add_menu_to_menu(list1,list2,id);
}
//查找学生信息
void tea_find_stu(StuList* list1,TeaList* list2,int id)
{
	system("clear");
	printf("＊＊＊＊＊查找学生＊＊＊＊＊\n");
	int num = 0;
	printf("请输入学号：");
	scanf("%d",&num);
	getchar();
	
	if(-1 == find_id_stu_int(list1,num))
	{
		printf("此人不存在！\n");
	}
	else
	{
		Stu* student = find_id_stu_node(list1,num)->data;
		if(0 == student->back)
		{
			printf("此人已被退学！\n");
		}
		else
		{
			system("clear");
			printf("学号\t姓名\t性别\t语文\t数学\t英语\t排名\n");
			printf("%d\t%s\t%s\t%g\t%g\t%g\t%d\n",student->id,student->name,student->sex,student->chinese,student->math,student->english,student->rank);
		}
	}
	tea_add_menu_to_menu(list1,list2,id);
}
//成绩排序
void tea_order_stu(StuList* list1,TeaList* list2,int id,char index)
{
	system("clear");
	switch(index)
	{
		case 0:QuickSort_sum(list1->head,list1->tail);break;
		case 1:QuickSort_chinese(list1->head,list1->tail);break;
		case 2:QuickSort_math(list1->head,list1->tail);break;
		case 3:QuickSort_english(list1->head,list1->tail);break;
		case 4:QuickSort_ave(list1->head,list1->tail);break;
	}
	
	printf("排名\t学号\t姓名\t总分\t语文\t数学\t英语\t平均分\n");
	int count = 1;
	for(Node* node=list1->head;node;node=node->next)
	{
		Stu* stu = node->data;
		printf("%d\t%d\t%s\t%g\t%g\t%g\t%g\t%g\n",count++,stu->id,stu->name,stu->sum,stu->chinese,stu->math,stu->english,stu->ave);
	}
	printf("＊＊＊＊＊按任意键返回＊＊＊＊＊\n");
	getch();
	show_teacher_order(list1,list2,id);
}
/*
//快速排序
void Quick_sum(Node* head,Node* tail)
{
	if(NULL == head || NULL == tail || head == tail)
		return;
	if(NULL == head->next)
		return;	
	Node* left = head;
	Node* right = tail;
	//标杆
	Stu* pivot = left->data;
	
	Stu* stu_left = left->data;
	Stu* stu_right = right->data;
	
	while(left != right)
	{
		printf("循环\n");
		while(left!=right && stu_right->sum >= pivot->sum)
		{
			printf("向左走\n");
			right = right->prev;
			stu_right = right->data;
		}
		if(left != right)
		{
			printf("%p == %p\n",stu_left,stu_right);
			stu_left = stu_right;
			printf("%p == %p\n",stu_left,stu_right);
		}

		while(left!=right && stu_left->sum <= pivot->sum)
		{
			printf("向又走\n");
			left = left->next;
			stu_left = left->data;
		}
		if(left != right)
		{
			printf("%p == %p\n",stu_right,stu_left);
			stu_right = stu_left;
			printf("%p == %p\n",stu_right,stu_left);
		}
	}
	stu_left = pivot;
	printf("====%p\n",stu_left);

	printf("******\n");
	Quick_sum(head,left->prev);
	Quick_sum(left->next,tail);
}
*/
/*
void QuickSort_sum(Node* head,Node* tail)
{
	//为空或只有一个数则返回
	if(NULL == head || NULL == head->next)
		return;
	
	Node*  pivot = head;
	Node*  prev = head;
	Node*  cur = head->next;
	
	Stu* temp = NULL;
	while(cur != tail->next)
	{
		Stu* stu_pivot = pivot->data;
		Stu* stu_cur = cur->data;
		if(stu_cur->sum > stu_pivot->sum)
		{
			prev = prev->next; 
			swap(prev,cur);
		}
		cur = cur->next;
	}
	swap(pivot, prev);

	QuickSort_sum(pivot, prev);
	QuickSort_sum(prev->next, tail);
}	
*/

void QuickSort_sum(Node* head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* pivot=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		Stu* stu_f=pivot->data;
		Stu* stu_c=cur->data;
		if(stu_f->sum < stu_c->sum)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,pivot);
	QuickSort_sum(head,prev);
	QuickSort_sum(prev->next,tail);
}	
void QuickSort_chinese(Node* head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* pivot=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		Stu* stu_f=pivot->data;
		Stu* stu_c=cur->data;
		if(stu_f->chinese < stu_c->chinese)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,pivot);
	QuickSort_chinese(head,prev);
	QuickSort_chinese(prev->next,tail);
}
void QuickSort_math(Node* head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* pivot=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		Stu* stu_f=pivot->data;
		Stu* stu_c=cur->data;
		if(stu_f->math < stu_c->math)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,pivot);
	QuickSort_math(head,prev);
	QuickSort_math(prev->next,tail);
}
void QuickSort_english(Node* head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* pivot=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		Stu* stu_f=pivot->data;
		Stu* stu_c=cur->data;
		if(stu_f->english < stu_c->english)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,pivot);
	QuickSort_english(head,prev);
	QuickSort_english(prev->next,tail);
}
void QuickSort_ave(Node* head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* pivot=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		Stu* stu_f=pivot->data;
		Stu* stu_c=cur->data;
		if(stu_f->ave < stu_c->ave)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,pivot);
	QuickSort_ave(head,prev);
	QuickSort_ave(prev->next,tail);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
