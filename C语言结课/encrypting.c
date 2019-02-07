#include "include.h"

//加密算法模块
void ENCRYPTING(char *pw)  //形式参数定义为指针去接受，好处就是可以跨函数操作数据，就不再需要去返回了 
{
    u8 i;
    long int tmp0=0,tmp1;
    for( i=0;i<strlen(pw)-1;i++ )
    {
    	tmp0 = ((u8)pw[i]^((u8)pw[strlen(pw)-1-i] >> 2)) >> 1;  //加密算法第一步： 字符强制转化为无符号整形并进行异或运算，对倒序转换后的元素进行右移，处理后的进行整体右移 
        if(i < strlen(pw)-1 ) tmp1 = ((u8)pw[i]&(u8)pw[i+1]);   //防止下一位是 \0 
        else tmp1 = 1;
        tmp0 = tmp1+tmp0;
 //       printf("Text Info: No.%u , PW: %c , Sum1: %u ,Sum2: %u , Lenth: %u\n",i,uncrypted[i],(u8)uncrypted[i],(u8)uncrypted[strlen(uncrypted)-1-i],strlen(uncrypted));
        pw[i] = (char)abs(tmp0)%254;  //tmp0取模后求余，防止强制转换字符后出现问题 
    }
//    pw[strlen(pw)] = '\0';
}
//完工

//密码重置模块 
void RESET_PASSWORD(void)
{
	u8 i=0;
    FILE *cr;
    cr = fopen(".password","wb+"); //二进制写入 
    printf("密码修改模式\n");
    char read1[17],read2[17];
    printf("输入新密码:");
    char c;
    while( 1 ) 
    {
        c = getch();  //读取一个字符到c 
        if( c == '\r' ) break; //Windows换行符为 \r\n ，读到\r就立即跳出 
        if( c == '\b' )  //读到退格时就删除 
        {
            printf("\b \b");
            i=i-1;
            continue;
        }
        printf("*");
        read1[i] = c;
        i++;
    }
    read1[i]='\0';
    printf("\n");
    i=0;
    if( strlen(read1) >= 17 )
    {
        printf("密码太长!需要小于等于16位!\n");
        exit(-1);
    }
    printf("确认新密码:");
    while( 1 )
    {
        c = getch();
        if( c == '\r' ) break;
        printf("*");
        read2[i] = c;
        i++;
    }
    read2[i]='\0';
    printf("\n");
    if( strcmp(read1,read2) != 0 )
    {
        printf("两次输入的密码不一样!\n");
        getchar();
        getchar();
        exit(-1);
    }
    printf("创建密码中...\n");
    ENCRYPTING(read1);
	for( ;i<=17;i++ )
    {
    	read1[i]='\0';
	}
    fwrite(read1,sizeof(read1),1,cr);
    fclose(cr);
    printf("完成\n");
}

int CHECK_PW(void)
{
	printf("输入密码：");
	char read[17];
	char c;
	u8 i=0;
    while( 1 ) 
    {
        c = getch();  //读取一个字符到c 
        if( c == '\r' ) break; //Windows换行符为 \r\n ，读到\r就立即跳出 
        if( c == '\b' )  //读到退格时就删除 
        {
            printf("\b \b");
            i=i-1;
            continue;
        }
        printf("*");
        read[i] = c;
        i++;
    }
    printf("\n");
    read[i]='\0';
    char file[17];
    ENCRYPTING(read);
    for( ;i<=17;i++ )
    {
    	read[i]='\0';
	}
    FILE *pw=fopen(".password","rb+");
    fread(file,17,1,pw);
    fclose(pw);
    if( memcmp( file,read,16 ) !=0 ) return 0;
    else return 1;
}

