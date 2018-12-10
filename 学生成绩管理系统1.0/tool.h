#ifndef TOOL_H
#define TOOL_H
#include<stdio.h>
#include<getch.h>
#include<stdlib.h>
void anykey_continue(void);
void show_msg(char* msg,int sec);
char get_cmd(char start,char end);
void clear_stdin(void);
char* get_str(char* str,size_t size);
void hide(char *pass);
#endif

