#include "fuction.h"
//头文件不用include.h是因为fuction.h已经包含，并且此处输出的数据需要是处理过的，故处理函数应该以头文件形式存在 

//磁盘文件读入模块 
void DISK_FILE_READ(void)
{
    u8 i=0;
    //判断文件是否存在或者权限是否可读,access()函数用于判断文件属性,文件正常时返回0,当文件属性全部正常时最后返回1
	if( access("S_Info.txt",4) == 0 && access("C_Info.txt",4) == 0 && access("Student_Info.txt",4) == 0 ) ;
	//任一文件不存在或者权限错误,返回0
    else
    {
        printf("权限错误或者文件不存在\n");
        getchar();
        getchar();
        exit(-1);
    }
    
	sex_list = fopen("S_Info.txt","r");
	college_list = fopen("C_Info.txt","r");
	stu_list = fopen("Student_Info.txt","r");
    
    //学院信息流读入
    i=1;
    while(!feof(college_list))
    {
        fscanf(college_list,"%u%s",&college_e[i].cid,college_e[i].c_name);
        i++;
    }
    fclose(college_list);
    
    //性别信息流读入
    i=0;
    while(!feof(sex_list))
    {
        fscanf(sex_list,"%u%s",&sex_e[i].eid,sex_e[i].e_name);
        i++;
    }
    sex_e[2] = sex_e[1];
    sex_e[1] = sex_e[0];
    sex_e[0] = sex_e[2];
    fclose(sex_list);
    
    //学生信息流读入
    i=0;
    while(!feof(stu_list))
    {
        fscanf(stu_list,"%lu%s%u%u%u%u%u%u%u%u%u%u%u%u",&stu[i].sid,stu[i].name,&stu[i].sex,&stu[i].college,&stu[i].scores[0],&stu[i].scores[1],&stu[i].scores[2],&stu[i].scores[3],&stu[i].scores[4],&stu[i].scores[5],&stu[i].scores[6],&stu[i].scores[7],&stu[i].scores[8],&stu[i].scores[9]);
        i++;
    }
    fclose(stu_list);
    
    //以下为调试模式启用
    /**
    printf("MAIN : L:%d\n\n",sizeof(stu)/sizeof(stu[0]));
    i=0;
    while(i<=10)
    {
        printf("INFO: CID : %u\tC_NAME : %s \n",college_e[i].cid,college_e[i].c_name);
        i++;
    }
    i=0;
	while(i<=1)
    {
        printf("INFO: EID : %u\tE_NAME : %s \n",sex_e[i].eid,sex_e[i].e_name);
        i++;
    }
    i=0;
	while(i<= 99 )
    {
        printf("INFO: SID : %lu\tNAME : %s\tSEX : %u\tCOLLEGE : %u\tSCORES : %u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u  \n",stu[i].sid,stu[i].name,stu[i].sex,stu[i].college,stu[i].scores[0],stu[i].scores[1],stu[i].scores[2],stu[i].scores[3],stu[i].scores[4],stu[i].scores[5],stu[i].scores[6],stu[i].scores[7],stu[i].scores[8],stu[i].scores[9]);
        i++;
    }
    printf("\n\n\n IMP :::: %s \n\n\n",college_e[1].c_name);
    **/
}

//控制台输出，输出特定内容 
void TERMINAL_OUTPUT(u8 n)
{
	printf("%lu\t%s\t",stu[n].sid,stu[n].name);
	printf("%s\t",sex_e[stu[n].sex].e_name);
	printf("%10s",college_e[stu[n].college].c_name);
	for(u8 a=0;a<=9;a++)
	{
		printf("\t%u",stu[n].scores[a]);
	}
//	printf("%lu\n",stu[n].total);
	printf("\n");
}

//控制台输出，功能表 
int TERMINAL_PRINTF(void)
{
	int s; //功能表需要用
	printf("Copyright (C) 1999-2017 XueGao & GXZ & LQ & LYL.<i@xuegao.hk>\n\n");
	printf("==============学生成绩管理系统==============\n");
	printf("======Student Scores Management System======\n\n");
	printf("*******************功能表*******************\n");
	printf("  1.原始文件读取\n  2.按姓名拼音首字母排序并输出\n  3.按平均成绩排序并输出 \n  4.输出给定学院学生 \n  5.修改给定学生成绩信息\n  6.按姓名查询学生并且输出 \n  7.修改系统密码\n  0.退出\n");
	printf("********************************************\n");
//	printf("结构体长度: %d\n ",sizeof(stu)/sizeof(stu[0]));
	printf("请选择选项:");
	scanf("%d",&s);
	return s;
}

