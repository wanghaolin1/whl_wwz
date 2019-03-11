#include "all.h"


//创建学生或教师节点
Node* create_node(TYPE data)
{
	Node* node = malloc(sizeof(Node));
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return node;
}
//创建教师链表
TeaList* create_list_tea(void)
{
	TeaList* list = malloc(sizeof(TeaList));
	list->head = NULL;
	list->tail = NULL;
	list->cnt = 0;
	return list;
}
//创建学生链表
StuList* create_list_stu(void)
{
	StuList* list = malloc(sizeof(StuList));
	list->head = NULL;
	list->tail = NULL;
	list->cnt = 0;
	return list;
}

//尾添加学生
void addend_tail_list_stu(StuList* list,TYPE data)
{
	Node* node = create_node(data);
	if(0 == list->cnt)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	list->cnt++;
}
//尾添加教师
void addend_tail_list_tea(TeaList* list,TYPE data)
{
	Node* node = create_node(data);
	if(0 == list->cnt)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	list->cnt++;
}
/*
//遍历学生
void show_list_stu(StuList* list)
{
	//头遍历
	for(StuNode* node=list->head;node;node=node->next)
	{
		printf("%d ",node->id);
	}
	printf("\n");
}
*/
/*
//删除头
bool delete_head_list_stu(StuList* list)
{
	if(0 == list->cnt)
		return false;
	if(1 == list->cnt)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->head = list->head->next;
		free(list->head->prev);
		list->head->prev = NULL;
	}
	list->cnt--;
	return true;
}

//删除尾
bool delete_tail_list_stu(StuList* list)
{
	if(0 == list->cnt)
		return false;
	if(1 == list->cnt)
	{
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail = list->tail->prev;
		free(list->tail->next);
		list->tail->next = NULL;
	}
	list->cnt--;
	return true;
}

//访问
Node* access_list_stu(StuList* list,size_t index)
{
	if(index >= list->cnt)
		return NULL;
	Node* node = list->tail;
	if(index >= list->cnt/2)
	{
		for(int i=list->cnt-1;i>index;i--,node=node->prev);	
	}
	else
	{
		node = list->head;
		for(int i=0;i<index;i++,node=node->next);
	}
	return node;
}


//销毁
void destroy_list_stu(StuList* list)
{
	while(list->cnt)
	{
		delete_tail_list_stu(list);
	}
	free(list);
}
*/
