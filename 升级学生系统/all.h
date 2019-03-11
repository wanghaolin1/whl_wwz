#ifndef ALL_H
#define ALL_H
//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊头文件＊＊＊＊＊＊＊＊＊＊＊＊＊＊
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getch.h>
#include <string.h>
#include <time.h>
#define TYPE void*

extern int id_stu;
extern int id_tea;
//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊链表与结点＊＊＊＊＊＊＊＊＊＊＊＊＊　

//公共节点
typedef struct Node
{
	struct Node* prev;
	void* data;
	struct Node* next; 
}Node;

//设计学生双向链表
typedef struct StuList
{
	Node* head;
	Node* tail;
	size_t cnt;
}StuList;

//设计教师双向链表
typedef struct TeaList
{
	Node* head;
	Node* tail;
	size_t cnt;
}TeaList;


//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊学生与教师结构体＊＊＊＊＊＊＊＊＊＊＊＊＊

//设计学生结构体
typedef struct Stu
{
	int id;//账号
	char name[20];//姓名
	char sex[10];//性别
	int age;//年龄
	int year;//出生年份
	float chinese;//语文成绩
	float math;//数学成绩
	float english;//英语成绩
	float ave;//平均分
	float sum;//总分
	int c_rank;//语文排名
	int m_rank;//数学排名
	int e_rank;//英语排名
	int rank;//总分排名
	char flag;//密码标志位
	char back;//退学标志位
}Stu;

//设计教师结构体
typedef struct Tea
{
	int id;//工号
	char pw[20];//密码
	char name[20];//姓名
	char sex[10];//性别
	int age;//年龄
	int year;//出生年份
	int work;//入职年份
	char ls;//工龄
	char flag;//密码标志位
	char back;//退学标志位
}Tea;

//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊学生链表操作＊＊＊＊＊＊＊＊＊＊＊＊＊
Node* find_id_stu_node(StuList* list,int id);
int find_id_stu_int(StuList* list,int id);
//创建学生节点
Node* create_node(TYPE data);
//创建学生链表
StuList* create_list_stu(void);
//尾添加学生
void addend_tail_list_stu(StuList* list,TYPE data);
//遍历学生
void show_list_stu(StuList* list);
//删除头
bool delete_head_list_stu(StuList* list);
//删除尾
bool delete_tail_list_stu(StuList* list);
//访问学生
Node* access_list_stu(StuList* list,size_t index);

//销毁学生链表
void destroy_list_stu(StuList* list);

//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊教师链表操作＊＊＊＊＊＊＊＊＊＊＊＊＊

//创建教师链表
TeaList* create_list_tea(void);

//尾添加教师
void addend_tail_list_tea(TeaList* list,TYPE data);


//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊系统基本功能＊＊＊＊＊＊＊＊＊＊＊＊＊　
int len_file(char* file);
void show_write_tea(void);
void show_write_stu(void);
void show_read_tea(void);
void show_read_stu(void);
Stu* encrypt_stu(Stu* stu,char key);
Stu* decipher_stu(Stu* stu,char key);
Node* find_id_tea_node(TeaList* list,int id);
int find_id_tea_int(TeaList* list,int id);
//显示指令界面
void show_first_menu(void);

void write_stu(StuList* list);
void write_tea(TeaList* list);
//年龄函数
int age_year(int year);

//获取按键
int get_first_key(void);
void get_tea_key(StuList* list1,TeaList* list2,int id);
void get_adm_key(StuList* list1,TeaList* list2);
void get_tea_oder_key(StuList* list1,TeaList* list2,int id);

//返回函数
void tea_add_menu_to_menu(StuList* list1,TeaList* list2,int id);
void adm_add_menu_to_menu(StuList* list1,TeaList* list2);
//查找函数
int find_id_tea(int id);
int find_id_adm(int id);

//登录界面
int login_menu(StuList* list1,TeaList* list2,char num);

//显示菜单界面
void show_teacher_menu(StuList* list1,TeaList* list2,int id);
void show_admini_menu(StuList* list1,TeaList* lis2);
void show_teacher_order(StuList* list1,TeaList* list2,int id);
void show_all_stu(StuList* list1,TeaList* list2,int id);
void show_all_tea(StuList* list1,TeaList* list2);

//教师功能函数
bool read_stu(StuList* list);
bool read_tea(TeaList* list);
void tea_add_stu(StuList* list1,TeaList* list2,int id);
void tea_del_stu(StuList* list1,TeaList* list2,int id);
void tea_mod_stu(StuList* list1,TeaList* list2,int id);
void tea_find_stu(StuList* list1,TeaList* list2,int id);
void tea_order_stu(StuList* list1,TeaList* list2,int id,char index);

//排名函数
void QuickSort_sum(Node* head,Node* tail);
void Quick_sum(Node* head,Node* tail);
void QuickSort_chinese(Node* head,Node* tail);
void QuickSort_math(Node* head,Node* tail);
void QuickSort_english(Node* head,Node* tail);
void QuickSort_ave(Node* head,Node* tail);
void swap(Node* node1,Node* node2);

//管路员功能函数
void adm_add_tea(StuList* list1,TeaList* list2);
void adm_del_tea(StuList* list1,TeaList* list2);
void adm_mod_tea(StuList* list1,TeaList* list2);

Node* partion(Node* head,Node* left, Node* right,char index);
void quick_sort(Node* head, Node* left, Node* right,char index);

//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊over＊＊＊＊＊＊＊＊＊＊＊＊＊＊　







#endif
