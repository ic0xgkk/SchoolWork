#include "include.h"

//冒泡排序 ，按照中文首字母拼音排序输出 
void PRINTF_NAME(void)
{
	u16 a = 0;
	while(1)
	{
		for(u8 i=0;i<=98;i++) //不能为99是为了防止和101组空元素比较 
		{
			if( strcmp(stu[i].name,stu[i+1].name) > 0 )
			{
				stu[101] = stu[i];  //对调 
				stu[i] = stu[i+1];
				stu[i+1] = stu[101];
			}
		}
		if( a == 1000 ) break; //循环排序多次 
		else a++;
	}
	printf("学号\t姓名\t性别\t学院\t\t科目1\t科目2\t科目3\t科目4\t科目5\t科目6\t科目7\t科目8\t科目9\t科目10\n"); 
	for(u8 i=0;i<=99;i++)
	{
		TERMINAL_OUTPUT(i);
	}
}

//按平均成绩排序输出 
void MEAN_VALUE(void)
{
	for(u8 i=0;i<=99;i++)
	{
		stu[i].total = 0;
		for(u8 a=0;a<=9;a++)
		{
			stu[i].total = stu[i].total + stu[i].scores[a];
		}
	}
	u16 a=0;
	while(1)
	{
		for(u8 i=0;i<=98;i++)
		{
			if( stu[i].total < stu[i+1].total )
			{
				stu[101] = stu[i];
				stu[i] = stu[i+1];
				stu[i+1] = stu[101];
			}
		}
		if( a == 200 ) break;
		else a++;
	}
	printf("学号\t姓名\t性别\t学院\t\t科目1\t科目2\t科目3\t科目4\t科目5\t科目6\t科目7\t科目8\t科目9\t科目10\t\n"); 
	for(u8 i=0;i<=99;i++)
	{
		TERMINAL_OUTPUT(i);
	}
}

//按学院输出 
void PRINTF_COLLEGE(void)
{
	printf("编号\t学院\n");
	for(u8 i=1;i<=10;i++)
	{
		
		printf("%u\t%s\n",college_e[i].cid,college_e[i].c_name);
	}
	printf("请输入上面输出的学院的编号来输出学生信息:"); 
	u8 sel;
	scanf("%u",&sel);
	printf("学号\t姓名\t性别\t学院\t\t科目1\t科目2\t科目3\t科目4\t科目5\t科目6\t科目7\t科目8\t科目9\t科目10\t\n"); 
	for(u8 i=0;i<=99;i++)
	{
		if( stu[i].college == sel )
		{
			TERMINAL_OUTPUT(i);
		}
	}

}

//查找学生并编辑模块 
void EDITING(void)
{
	char name[16];
	u8 tid=0;
	printf("据说你要编辑学生信息?先输入这个学生的姓名吧:");
	scanf("%s",name);
	for(u8 i=0;i<=99;i++)
	{
		if( i == 100 )
		{
			printf("查无此人,程序即将退出!\n");
			getchar();
			getchar();
			exit(-1);
		}
		if( strcmp(name,stu[i].name) == 0 )
		{
			tid = i;
//			printf("%s\n\n",stu[tid].name);
			break;
		} 
	}
	printf("学号\t姓名\t性别\t学院\t\t科目1\t科目2\t科目3\t科目4\t科目5\t科目6\t科目7\t科目8\t科目9\t科目10\t\n"); 
	TERMINAL_OUTPUT(tid);
	printf("现在开始请连续输入该学生的10个成绩,以空格隔开:");
	scanf("%u%u%u%u%u%u%u%u%u%u",&stu[tid].scores[0],&stu[tid].scores[1],&stu[tid].scores[2],&stu[tid].scores[3],&stu[tid].scores[4],&stu[tid].scores[5],&stu[tid].scores[6],&stu[tid].scores[7],&stu[tid].scores[8],&stu[tid].scores[9]);
	FILE *sinf;
	sinf = fopen("Student_Info.txt","w");
	for(u8 i=0;i<=99;i++)
	{
		fprintf(sinf,"%lu %s %u %u",stu[i].sid,stu[i].name,stu[i].sex,stu[i].college);
		for(u8 a=0;a<=9;a++)
		{
			fprintf(sinf," %u",stu[i].scores[a]);
		}
		fprintf(sinf,"\n");
	}
	fclose(sinf);
	printf("处理完成\n");
}

//查找学生并输出模块 
void FIND_STU(void)
{
	char name[16];
	printf("需要查找学生,请输入他的名字:");
	scanf("%s",name);
	u8 sel=0;
	for(u8 i=0;i<=99;i++)
	{
		if( strcmp(name,stu[i].name) == 0  )
		{
			sel = i;
			break;
		}
	}
	printf("学号\t姓名\t性别\t学院\t\t科目1\t科目2\t科目3\t科目4\t科目5\t科目6\t科目7\t科目8\t科目9\t科目10\t\n"); 
	TERMINAL_OUTPUT(sel);
	printf("数据如上\n");
}

