#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "menuc.h"
#include "tool.h"
#include "struct.h"

void quit(void)
{	
	FILE* stu_w=fopen("stu.txt","w");
	for(int i=0;i<stu_count;i++)
	{
		fwrite(&stu[i],92,1,stu_w);
	}
	
	FILE* tea_w=fopen("tea.txt","w");
	for(int i=0;i<tea_count;i++)
	{
		fwrite(&tea[i],60,1,tea_w);
	}

	FILE* ma_w=fopen("ma.txt","w");
	for(int i=0;i<ma_count;i++)
	{
		fwrite(&ma[i],44,1,ma_w);
	}
}	


/*void quit(void)
{	
	FILE* stu_w=fopen("stu.txt","w");
	for(int i=0;i<stu_count;i++)
	{
		fprintf(stu_w,"%d %s %s %c %s %d %d %d %f %d %d %d %d %d %d %d\n",stu[i].num,stu[i].password,stu[i].name,stu[i].sex,stu[i].age,stu[i].chinese,stu[i].math,stu[i].english,stu[i].avg,stu[i].sum,stu[i].rank_all,stu[i].rank_chinese,stu[i].rank_math,stu[i].rank_english,stu[i].index,stu[i].lock);
	}
	
	FILE* tea_w=fopen("tea.txt","w");
	for(int i=0;i<tea_count;i++)
	{
		fprintf(tea_w,"%d %s %s %c %s %d %d %d\n",tea[i].job_num,tea[i].password,tea[i].name,tea[i].sex,tea[i].age,tea[i].work_year,tea[i].lock,tea[i].index);
	}

	FILE* ma_w=fopen("ma.txt","w");
	for(int i=0;i<ma_count;i++)
	{
		fprintf(ma_w,"%s %s %d %d %d\n",ma[i].name,ma[i].password,ma[i].ma_num,ma[i].lock,ma[i].index);
	}
	
}	*/

int main()
{
	
	/*ma =malloc(sizeof(manager)*10);
	stu=malloc(sizeof(student)*100);
	tea=malloc(sizeof(teacher)*50);*/
	stu_count=0;
 	tea_count=0;
 	ma_count=0;
	
	FILE* stu_r=fopen("stu.txt","r");
	fseek(stu_r,0,SEEK_END);
	long ret_stu=ftell(stu_r);
	rewind(stu_r);
	stu_count=ret_stu/92;
	for(int i=0;i<stu_count;i++)
	{
		fread(&stu[i],92,1,stu_r);
	}
	
	
	FILE* tea_r=fopen("tea.txt","r");
	fseek(tea_r,0,SEEK_END);
	long ret_tea=ftell(tea_r);
	rewind(tea_r);
	tea_count=ret_tea/60;
	for(int i=0;i<tea_count;i++)
	{
		fread(&tea[i],60,1,tea_r);
	}
	

	FILE* ma_r=fopen("ma.txt","r");
	fseek(ma_r,0,SEEK_END);
	long ret_ma=ftell(ma_r);
	rewind(ma_r);
	ma_count=ret_ma/44;
	for(int i=0;i<ma_count;i++)
	{
		fread(&ma[i],44,1,ma_r);
	}
	
	/*FILE* stu_r=fopen("stu.txt","r");
	while(!feof(stu_r))
	{
		fscanf(stu_r,"%d %s %s %c %s %d %d %d %f %d %d %d %d %d %d %d\n",&stu[stu_count].num,stu[stu_count].password,stu[stu_count].name,&stu[stu_count].sex,stu[stu_count].age,&stu[stu_count].chinese,&stu[stu_count].math,&stu[stu_count].english,&stu[stu_count].avg,&stu[stu_count].sum,&stu[stu_count].rank_all,&stu[stu_count].rank_chinese,&stu[stu_count].rank_math,&stu[stu_count].rank_english,&stu[stu_count].index,&stu[stu_count].lock);
		stu_count++;
	}


	FILE* tea_r=fopen("tea.txt","r");
	while(!feof(tea_r))
	{
		fscanf(tea_r,"%d %s %s %c %s %d %d %d\n",&tea[tea_count].job_num,tea[tea_count].password,tea[tea_count].name,&tea[tea_count].sex,tea[tea_count].age,&tea[tea_count].work_year,&tea[tea_count].lock,&tea[tea_count].index);
		tea_count++;
	}


	FILE* ma_r=fopen("ma.txt","r");
	while(!feof(ma_r))
	{
		fscanf(ma_r,"%s %s %d %d %d\n",ma[ma_count].name,ma[ma_count].password,&ma[ma_count].ma_num,&ma[ma_count].lock,&ma[ma_count].index);
		ma_count++;
	}
	*/
	

	while(1)
	{
		major_menu();
		switch(get_cmd('0','4'))
		{
			case '1': manager_admin();break;
			case '2': teacher_admin();break;
			case '3': student_admin();break;
			case '0': quit();return 0;
			case '4': super_admin();break;
		}
	}
}





