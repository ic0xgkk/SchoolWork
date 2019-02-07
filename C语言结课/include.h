#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>   //密码加密算法需要用
#include <unistd.h>  //access函数需要用 
#include <conio.h>  //getch函数需要用 

//不想打太长的声明
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

//变量定义区
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
}stu[102];  //不要改小，会越界 ，并且要多留一个数组做临时交换用 

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

