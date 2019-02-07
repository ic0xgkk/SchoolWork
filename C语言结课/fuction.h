#include "include.h"

//ð������ ��������������ĸƴ��������� 
void PRINTF_NAME(void)
{
	u16 a = 0;
	while(1)
	{
		for(u8 i=0;i<=98;i++) //����Ϊ99��Ϊ�˷�ֹ��101���Ԫ�رȽ� 
		{
			if( strcmp(stu[i].name,stu[i+1].name) > 0 )
			{
				stu[101] = stu[i];  //�Ե� 
				stu[i] = stu[i+1];
				stu[i+1] = stu[101];
			}
		}
		if( a == 1000 ) break; //ѭ�������� 
		else a++;
	}
	printf("ѧ��\t����\t�Ա�\tѧԺ\t\t��Ŀ1\t��Ŀ2\t��Ŀ3\t��Ŀ4\t��Ŀ5\t��Ŀ6\t��Ŀ7\t��Ŀ8\t��Ŀ9\t��Ŀ10\n"); 
	for(u8 i=0;i<=99;i++)
	{
		TERMINAL_OUTPUT(i);
	}
}

//��ƽ���ɼ�������� 
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
	printf("ѧ��\t����\t�Ա�\tѧԺ\t\t��Ŀ1\t��Ŀ2\t��Ŀ3\t��Ŀ4\t��Ŀ5\t��Ŀ6\t��Ŀ7\t��Ŀ8\t��Ŀ9\t��Ŀ10\t\n"); 
	for(u8 i=0;i<=99;i++)
	{
		TERMINAL_OUTPUT(i);
	}
}

//��ѧԺ��� 
void PRINTF_COLLEGE(void)
{
	printf("���\tѧԺ\n");
	for(u8 i=1;i<=10;i++)
	{
		
		printf("%u\t%s\n",college_e[i].cid,college_e[i].c_name);
	}
	printf("���������������ѧԺ�ı�������ѧ����Ϣ:"); 
	u8 sel;
	scanf("%u",&sel);
	printf("ѧ��\t����\t�Ա�\tѧԺ\t\t��Ŀ1\t��Ŀ2\t��Ŀ3\t��Ŀ4\t��Ŀ5\t��Ŀ6\t��Ŀ7\t��Ŀ8\t��Ŀ9\t��Ŀ10\t\n"); 
	for(u8 i=0;i<=99;i++)
	{
		if( stu[i].college == sel )
		{
			TERMINAL_OUTPUT(i);
		}
	}

}

//����ѧ�����༭ģ�� 
void EDITING(void)
{
	char name[16];
	u8 tid=0;
	printf("��˵��Ҫ�༭ѧ����Ϣ?���������ѧ����������:");
	scanf("%s",name);
	for(u8 i=0;i<=99;i++)
	{
		if( i == 100 )
		{
			printf("���޴���,���򼴽��˳�!\n");
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
	printf("ѧ��\t����\t�Ա�\tѧԺ\t\t��Ŀ1\t��Ŀ2\t��Ŀ3\t��Ŀ4\t��Ŀ5\t��Ŀ6\t��Ŀ7\t��Ŀ8\t��Ŀ9\t��Ŀ10\t\n"); 
	TERMINAL_OUTPUT(tid);
	printf("���ڿ�ʼ�����������ѧ����10���ɼ�,�Կո����:");
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
	printf("�������\n");
}

//����ѧ�������ģ�� 
void FIND_STU(void)
{
	char name[16];
	printf("��Ҫ����ѧ��,��������������:");
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
	printf("ѧ��\t����\t�Ա�\tѧԺ\t\t��Ŀ1\t��Ŀ2\t��Ŀ3\t��Ŀ4\t��Ŀ5\t��Ŀ6\t��Ŀ7\t��Ŀ8\t��Ŀ9\t��Ŀ10\t\n"); 
	TERMINAL_OUTPUT(sel);
	printf("��������\n");
}

