#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>   //��������㷨��Ҫ��
#include <unistd.h>  //access������Ҫ�� 
#include <conio.h>  //getch������Ҫ�� 

//�����̫��������
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

//����������
static FILE *sex_list,*college_list,*stu_list;
//static char passwd[16];
//static char crypted[17];

static struct stu_info{
    u32 sid;
    char name[64];
    u8 sex;
    u8 college;
    u8 scores[10];
    u16 total;
}stu[102];  //��Ҫ��С����Խ�� ������Ҫ����һ����������ʱ������ 

static struct college_info{
    u8 cid;
    char c_name[512];
}college_e[16];

static struct sex_info{
    u8 eid;
    char e_name[8];
}sex_e[3];


void DISK_FILE_READ(void);
void ENCRYPTING(char *pw);
void RESET_PASSWORD(void);
void EDITING(void);
void TERMINAL_OUTPUT(u8 n);
void FIND_STU(void);
void MEAN_VALUE(void);
void PRINTF_COLLEGE(void);
void PRINTF_NAME(void);
void WAIT(void);
int TERMINAL_PRINTF(void);
int CHECK_PW(void);

