#include "fuction.h"
//ͷ�ļ�����include.h����Ϊfuction.h�Ѿ����������Ҵ˴������������Ҫ�Ǵ�����ģ��ʴ�����Ӧ����ͷ�ļ���ʽ���� 

//�����ļ�����ģ�� 
void DISK_FILE_READ(void)
{
    u8 i=0;
    //�ж��ļ��Ƿ���ڻ���Ȩ���Ƿ�ɶ�,access()���������ж��ļ�����,�ļ�����ʱ����0,���ļ�����ȫ������ʱ��󷵻�1
	if( access("S_Info.txt",4) == 0 && access("C_Info.txt",4) == 0 && access("Student_Info.txt",4) == 0 ) ;
	//��һ�ļ������ڻ���Ȩ�޴���,����0
    else
    {
        printf("Ȩ�޴�������ļ�������\n");
        getchar();
        getchar();
        exit(-1);
    }
    
	sex_list = fopen("S_Info.txt","r");
	college_list = fopen("C_Info.txt","r");
	stu_list = fopen("Student_Info.txt","r");
    
    //ѧԺ��Ϣ������
    i=1;
    while(!feof(college_list))
    {
        fscanf(college_list,"%u%s",&college_e[i].cid,college_e[i].c_name);
        i++;
    }
    fclose(college_list);
    
    //�Ա���Ϣ������
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
    
    //ѧ����Ϣ������
    i=0;
    while(!feof(stu_list))
    {
        fscanf(stu_list,"%lu%s%u%u%u%u%u%u%u%u%u%u%u%u",&stu[i].sid,stu[i].name,&stu[i].sex,&stu[i].college,&stu[i].scores[0],&stu[i].scores[1],&stu[i].scores[2],&stu[i].scores[3],&stu[i].scores[4],&stu[i].scores[5],&stu[i].scores[6],&stu[i].scores[7],&stu[i].scores[8],&stu[i].scores[9]);
        i++;
    }
    fclose(stu_list);
    
    //����Ϊ����ģʽ����
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

//����̨���������ض����� 
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

//����̨��������ܱ� 
int TERMINAL_PRINTF(void)
{
	int s; //���ܱ���Ҫ��
	printf("Copyright (C) 1999-2017 XueGao & GXZ & LQ & LYL.<i@xuegao.hk>\n\n");
	printf("==============ѧ���ɼ�����ϵͳ==============\n");
	printf("======Student Scores Management System======\n\n");
	printf("*******************���ܱ�*******************\n");
	printf("  1.ԭʼ�ļ���ȡ\n  2.������ƴ������ĸ�������\n  3.��ƽ���ɼ�������� \n  4.�������ѧԺѧ�� \n  5.�޸ĸ���ѧ���ɼ���Ϣ\n  6.��������ѯѧ��������� \n  7.�޸�ϵͳ����\n  0.�˳�\n");
	printf("********************************************\n");
//	printf("�ṹ�峤��: %d\n ",sizeof(stu)/sizeof(stu[0]));
	printf("��ѡ��ѡ��:");
	scanf("%d",&s);
	return s;
}

