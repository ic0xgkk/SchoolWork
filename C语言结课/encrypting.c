#include "include.h"

//�����㷨ģ��
void ENCRYPTING(char *pw)  //��ʽ��������Ϊָ��ȥ���ܣ��ô����ǿ��Կ纯���������ݣ��Ͳ�����Ҫȥ������ 
{
    u8 i;
    long int tmp0=0,tmp1;
    for( i=0;i<strlen(pw)-1;i++ )
    {
    	tmp0 = ((u8)pw[i]^((u8)pw[strlen(pw)-1-i] >> 2)) >> 1;  //�����㷨��һ���� �ַ�ǿ��ת��Ϊ�޷������β�����������㣬�Ե���ת�����Ԫ�ؽ������ƣ������Ľ����������� 
        if(i < strlen(pw)-1 ) tmp1 = ((u8)pw[i]&(u8)pw[i+1]);   //��ֹ��һλ�� \0 
        else tmp1 = 1;
        tmp0 = tmp1+tmp0;
 //       printf("Text Info: No.%u , PW: %c , Sum1: %u ,Sum2: %u , Lenth: %u\n",i,uncrypted[i],(u8)uncrypted[i],(u8)uncrypted[strlen(uncrypted)-1-i],strlen(uncrypted));
        pw[i] = (char)abs(tmp0)%254;  //tmp0ȡģ�����࣬��ֹǿ��ת���ַ���������� 
    }
//    pw[strlen(pw)] = '\0';
}
//�깤

//��������ģ�� 
void RESET_PASSWORD(void)
{
	u8 i=0;
    FILE *cr;
    cr = fopen(".password","wb+"); //������д�� 
    printf("�����޸�ģʽ\n");
    char read1[17],read2[17];
    printf("����������:");
    char c;
    while( 1 ) 
    {
        c = getch();  //��ȡһ���ַ���c 
        if( c == '\r' ) break; //Windows���з�Ϊ \r\n ������\r���������� 
        if( c == '\b' )  //�����˸�ʱ��ɾ�� 
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
        printf("����̫��!��ҪС�ڵ���16λ!\n");
        exit(-1);
    }
    printf("ȷ��������:");
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
        printf("������������벻һ��!\n");
        getchar();
        getchar();
        exit(-1);
    }
    printf("����������...\n");
    ENCRYPTING(read1);
	for( ;i<=17;i++ )
    {
    	read1[i]='\0';
	}
    fwrite(read1,sizeof(read1),1,cr);
    fclose(cr);
    printf("���\n");
}

int CHECK_PW(void)
{
	printf("�������룺");
	char read[17];
	char c;
	u8 i=0;
    while( 1 ) 
    {
        c = getch();  //��ȡһ���ַ���c 
        if( c == '\r' ) break; //Windows���з�Ϊ \r\n ������\r���������� 
        if( c == '\b' )  //�����˸�ʱ��ɾ�� 
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

