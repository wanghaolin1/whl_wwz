#include "tool.h"
#include<string.h>
#include<getch.h>
#include"struct.h"

void anykey_continue(void)
{
	puts("按任意键返回......");
	getch();
}

void show_msg(char* msg,int sec)
{
	printf("\033[01;31m%s\n\033[00m",msg);
	sleep(sec);
}

char get_cmd(char start,char end)
{
	while(1)
	{
		char cmd = getch();
		if(cmd >= start && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}

void clear_stdin(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
}

char* get_str(char* str,size_t size)
{
	if(NULL==str) return str;
	clear_stdin();
	fgets(str,size,stdin);
	if(size-1 == strlen(str))
	{
		if('\n' == str[size-2])
			str[size-2] = '\0';
		else
			clear_stdin();
	}
	else
		str[strlen(str)-1]='\0';
}

void hide(char *pass)
{
	for(int i = 0;i<10;i++)
	{
		pass[i] = getch();
		if(i==0 && 127==pass[i])
		{	i--;
			printf("\b \b");
			continue;
		}
		if(i>0&&127 == pass[i])
		{
			i-=2;	
			printf("\b \b");
			continue;
		}
		if('\n' == pass[i])
		{
			pass[i] = '\0';
			break;
		}
		putchar('*');
	}
	printf("\n");
}





