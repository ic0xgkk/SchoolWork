#include "include.h"


int main()
{
	system("title ѧ����Ϣ����ϵͳ ");   //�ն˱��� 
	system("color 2f");   //�ն���ɫ 
	system("mode con cols=180");  //�ն˿��180 
	while(1)
	{
		if( CHECK_PW() != 1 )
		{
			printf("\n--����������������룡\n"); 
			continue;
		}
		else break;
	}
	printf("\n");
	int sec;
    while(1)
	{
		sec = TERMINAL_PRINTF();
		if( !(sec >=0 && sec<= 7) )  //�ж��û�������ֵ�Ƿ����ѡ����� 
		{
			printf("��������,����������!\n");
			WAIT();
			continue;
		}
		switch( sec )
		{
			case 1:DISK_FILE_READ();printf("�������\n");WAIT();break;
			case 2:PRINTF_NAME();DISK_FILE_READ();WAIT();break;
			case 3:MEAN_VALUE();DISK_FILE_READ();WAIT();break;
			case 4:PRINTF_COLLEGE();WAIT();break;
			case 5:DISK_FILE_READ();EDITING();WAIT();break;
			case 6:DISK_FILE_READ();FIND_STU();WAIT();break;
			case 7:RESET_PASSWORD();WAIT();break;
			case 0:exit(0);
		}
	}
}

