#include <stdio.h>
#include "tools.h"
// 清屏
void clear_scr(void)
{
	system("clear");
}

// 清理输入缓冲区
void clear_stdin(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
}

// get_0to9()
char get_0to9(void)
{
	char ch = 0;
	while(1)
	{
		ch = getch();
		if(ch >= '0' && ch <= '9' || ch == '.' || ch == '\n' || ch == 127)
			break;
	}
	return ch;
}

// 输入字符限制,str为存放输入数据的数组,size为存放上限
char* get_lim(char* str ,size_t size)
{
	clear_stdin();
	char ch;
	int cnt = 0;
	while(1)
	{
		// 判断是否为空字符
		if((ch = get_0to9()) == '\n' && cnt == 0)
		{
			return NULL;
		}

		// 判断是否按下回车
		if(ch  == '\n')
		{
			// 最后一个输入'\0'作为结束
			str[cnt] = '\0';  

			puts("");
			//返回得到的数组
			return str;
		}

		// 判断是否按下退格
		if(ch == 127)
		{
			// 判断当前是否已经有字符了
			if(cnt > 0)
			{

				//　下标减一
				cnt--;
				printf("\b \b");
			}
			continue;
		}

		// 判断是否到达上限
		if(cnt == size - 1)
		{
			continue;
		}

		// 将输入的字符放入数组中
		str[cnt++] = ch;
		
		// 打印字符
		printf("%c",ch);
	}
}

// 密码保密输入
char* get_key_lim(char* str ,size_t size)
{
	clear_stdin();
	char ch;
	int cnt = 0;
	while(1)
	{
		// 判断是否为空字符
		if((ch = getch()) == '\n' && cnt == 0)
		{
			return NULL;
		}

		// 判断是否按下回车
		if(ch == '\n')
		{
			// 最后一个输入'\0'作为结束
			str[cnt] = '\0';  

			puts("");
			//返回得到的数组
			return str;
		}

		// 判断是否按下退格
		if(ch == 127)
		{
			// 判断当前是否已经有字符了
			if(cnt > 0)
			{

				//　下标减一
				cnt--;
				printf("\b \b");
			}
			continue;
		}

		// 判断是否到达上限
		if(cnt == size - 1)
		{
			continue;
		}

		// 将输入的字符放入数组中
		str[cnt++] = ch;
		
		// 打印字符
		printf("*");
	}
}

//获取字符串
char* get_str(char* str,size_t size)
{
	clear_stdin();

	fgets(str,size,stdin);
	size_t len = strlen(str);

	if(str[len-1] == '\n') 
	{
		str[len-1] = '\0';
	}

	clear_stdin();
}


//显示提示信息
void show_msg(char* msg,size_t sec)
{
	printf("\33[;34m");
	printf("*** %s *** \n",msg);
	sleep(sec);
	printf("\33[0m");
}

//获取指令
char get_cmd(char start,char end)
{
	clear_stdin();

	printf("请输入指令:");
	while(true)
	{
		char val = getch();
		if(val >= start && val <= end)
		{
			printf("%c\n",val);
			return val;
		}
	}
}


// 判断密码还有几次输入
bool judge_pass(char* str1,char* str2,size_t cnt)
{
	while(strcmp(str1,str2) != 0)
		{
			// 判断是否还有输入次数
			if(cnt > 1)
			{	
				printf("\n输入错误,还有%d次机会\n",--cnt);
				printf("请输入密码:");
	 			while(NULL == get_key_lim(str1,20));
				continue;
			}
			return false;
		}
	return true;	
}

void press_anykey(void)
{
	clear_stdin();
	puts("-------按任意键返回-------");
	getch();
}

char y_or_n(void)
{
	char ch;
	while(1)
	{
		ch = getch();
		if(ch == 'n' || ch == 'N' || ch == 'y' || ch == 'Y')
			break;
	}
	return ch;
}

Acc* encry(Acc* str,int size)
{	
	char buf[sizeof(Acc)] = {};
	memcpy(buf,str,sizeof(Acc));
	int i;
	for(i = 0;i < size;i++)
	{
		buf[i] ^= 10;
	}
	memcpy(str,buf,sizeof(buf));
	return str;
}
