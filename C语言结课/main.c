#include "include.h"


int main()
{
	system("title 学生信息管理系统 ");   //终端标题 
	system("color 2f");   //终端颜色 
	system("mode con cols=180");  //终端宽度180 
	while(1)
	{
		if( CHECK_PW() != 1 )
		{
			printf("\n--密码错误，请重新输入！\n"); 
			continue;
		}
		else break;
	}
	printf("\n");
	int sec;
    while(1)
	{
		sec = TERMINAL_PRINTF();
		if( !(sec >=0 && sec<= 7) )  //判断用户的输入值是否符合选项序号 
		{
			printf("输入有误,请重新输入!\n");
			WAIT();
			continue;
		}
		switch( sec )
		{
			case 1:DISK_FILE_READ();printf("读入完成\n");WAIT();break;
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

