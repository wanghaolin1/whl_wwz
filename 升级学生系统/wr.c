#include "all.h"

//读教师文件
bool read_tea(TeaList* list)
{
	FILE* frp = fopen("教师信息.txt","rb");
	
	if(NULL == frp)
		return false;
	printf("嘟列灭\n");	
	int len = len_file("教师信息.txt");
	
	int count = len/sizeof(Tea);
	if(0 == count)
	{
		fclose(frp);
		return false;
	}
	for(int i=0;i<count;i++)
	{
		
		char* p = malloc(sizeof(Tea));
		
		fread(p,sizeof(Tea),1,frp);
	
		
		for(int j=0;j<sizeof(Tea);j++)
		{
			p[j] = p[j] ^ 'S';
		}
		
		Tea* tea = (Tea*)p;
		
		addend_tail_list_tea(list,tea);	
	}
	id_tea += count;
	fclose(frp);
	show_read_tea();
	
}
//读取进度条
void show_read_tea(void)
{
	system("clear");
	printf("正在读取教师文件！\n");
	printf("进度：%%%d\n",rand()%50);
	usleep(800000);
	printf("进度：%%100\n");
	usleep(400000);
	printf("读取教师文件成功！\n");
	usleep(800000);
}
//写教师文件
void write_tea(TeaList* list)
{
	FILE* fwp = fopen("教师信息.txt","wb");
	
	Node* node = list->head;
	if(NULL == node)
	{
		fclose(fwp);
		return;
	}
	
	while(node)
	{
		Node* tea = node->data;
		char* ch = malloc(sizeof(Tea));
		char* p = (char*)tea;
		for(int i=0;i<sizeof(Tea);i++)
		{
			ch[i] = p[i]^'S';
		}
		fwrite(ch,sizeof(Tea),1,fwp);
		node = node->next;
	}
	fclose(fwp);
	show_write_tea();
}
//写入进度条
void show_write_tea(void)
{
	system("clear");
	printf("正在保存教师文件！\n");
	printf("进度：%%%d\n",rand()%50);
	usleep(800000);
	printf("进度：%%100\n");
	usleep(400000);
	printf("保存教师文件成功！\n");
	usleep(800000);
}
//获取文件长度
int len_file(char* file)
{
	FILE* frp = fopen(file,"r");
	if(NULL == frp)
		return -1;
	else
	{
		fseek(frp, 0, SEEK_END);
		int length = ftell(frp);
		return length;//获取文件大小
	}
}
//读学生文件
bool read_stu(StuList* list)
{
	FILE* frp = fopen("学生信息.txt","rb");
	
	if(NULL == frp)
		return false;
		
	int len = len_file("学生信息.txt");
	
	int count = len/sizeof(Stu);
	
	if(0 == count)
	{
		fclose(frp);
		return false;
	}
	
	for(int i=0;i<count;i++)
	{
		
		char* p = malloc(sizeof(Stu));
		
		fread(p,sizeof(Stu),1,frp);
	
		for(int j=0;j<sizeof(Stu);j++)
		{
			p[j] = p[j] ^'S';
			//printf("****%c\n",p[j]);	
		}
		
		Stu* stu = (Stu*)p;
		
		addend_tail_list_stu(list,stu);	
	}
	id_stu += count;
	fclose(frp);
	show_read_stu();
}
void show_read_stu(void)
{
	system("clear");
	printf("正在读取学生文件！\n");
	printf("进度：%%47\n");
	usleep(800000);
	printf("进度：%%100\n");
	usleep(400000);
	printf("读取学生文件成功！\n");
	usleep(800000);
}
void write_stu(StuList* list)
{
	FILE* fwp = fopen("学生信息.txt","wb");
	
	Node* node = list->head;
	if(NULL == node)
	{
		fclose(fwp);
		return;
	}
	while(node)
	{
		Node* stu = node->data;
		char* ch = malloc(sizeof(Stu));
		char* p = (char*)stu;
		for(int i=0;i<sizeof(Stu);i++)
		{
			ch[i] = p[i]^'S';
	
		}
		fwrite(ch,sizeof(Stu),1,fwp);
		node = node->next;
	}
	fclose(fwp);
	show_write_stu();
}
void show_write_stu(void)
{
	system("clear");
	printf("正在保存学生文件！\n");
	printf("进度：%%37\n");
	usleep(800000);
	printf("进度：%%100\n");
	usleep(400000);
	printf("保存学生文件成功！\n");
	usleep(800000);
}
