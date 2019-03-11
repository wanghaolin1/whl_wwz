#ifndef _TOOLS_H_
#define _TOOLS_H_
#include <stdbool.h>
#include <getch.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
void clear_scr(void);

void clear_stdin(void);

char* get_lim(char* str,size_t num);

char* get_key_lim(char* str,size_t num);

char* get_str(char* str,size_t size);

void show_msg(char* msg,size_t sec);

char get_cmd(char start,char end);

bool judge_pass(char* str1,char* str2,size_t cnt);

void press_anykey(void);

char y_or_n(void);

Acc* encry(Acc* str,int size);
#endif// _TOOLS_H_
