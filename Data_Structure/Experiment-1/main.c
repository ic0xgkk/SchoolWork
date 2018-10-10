/*
Ice Cream <i@xuegao.hk>
This is an example program which written by Ice Cream.It only can be used in learning and watering.
You can catch me on my GayHub https://github.com/ic0xgkk and Blog https://blog.xuegao.hk
*/

/*
想了想，头指针索引有两个方案
1.　头指针即为操作的指针，跟随程序遍历，备份头指针，赋值时还原头指针位置以进行遍历（本程序就是这样）
2.　将头地址写入一个指针中，此指针不用来任何操作，需要插入时复制指针地址并遍历到尾部插入
*/

/*
This version only support to insert to footer
当前版本只支持从尾部插入，因为这个场景下不知道从中间插入有什么用处，就先不考虑了
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Books{
    uint64_t ISBN;
    char BookName[128];
    uint32_t PRICE;
    struct Books *next;
};
void *backup_header=NULL;
struct Books *head=NULL;
bool finished_loading=false;

void insert_b(uint64_t isbn, char bookname[], uint32_t price);
void search_b(void);
void delete_b(void);
void print_all(void);

int main()
{
    printf("\nBooks Management System - Tiny\n");
    printf("Loading book list...\n");

    FILE *f=fopen("book.txt","r");
    while(!feof(f))
	{
        char tmp[512];
        uint64_t isbn;
        uint32_t price;
        char bookname[128];
		memset(tmp, 0, sizeof(tmp));
		fgets(tmp, sizeof(tmp)-1, f); // 包含了换行符
		if( strlen(tmp) < 14 ) //　此处手动感谢TUNA成员帮我查出了读入空行的bug
		{
            break;
		}
		sscanf(tmp, "%lu%s%u\n",&isbn, bookname, &price);
		insert_b(isbn,bookname,price);
	}
	finished_loading=true;

    while(1)
    {
        uint32_t sel=0;
        printf("What do you want to do?\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print All\n");
        printf("Input the number and ENTER to do that you want do :");
        scanf("%u",&sel);

        switch(sel)
        {
            case 1:
            {
                uint64_t isbn=0;
                uint32_t price=0;
                char name[128]={0};

                printf("Insert Mode:\n");
                printf("Input ISBN:");
                scanf("%lu",&isbn);
                printf("Input BookName:");
                scanf("%s",name);
                printf("Input Price:");
                scanf("%u",&price);

                insert_b(isbn, name, price);
                printf("Done!\n");
            };break;
            case 2:delete_b();break;
            case 3:search_b();break;
            case 4:print_all();break;
            default:
            {
                printf("What the fuck?You must retry it!\n");
                break;
            }
        }
    }

}

void insert_b(uint64_t isbn, char bookname[], uint32_t price)
{
    struct Books *data;

    int tz=sizeof(struct Books);
    data=(struct Books *)malloc(tz);
    memset(data,0,tz);
    if(data==NULL)
    {
        printf("Malloc failed.\n");
        exit(-1);
    }

    if(head==backup_header && finished_loading==true)
    {
        while(1)
        {
            if(head->next==NULL)
            {
                break;
            }
            else
            {
                head=head->next;
                continue;
            }
        }
    }

    if(head==NULL)
        head=data;

    if(backup_header==NULL && finished_loading==false)
    {
        backup_header=head;
    }

    head->next=data;
    data->ISBN=isbn;
    strcpy( data->BookName, bookname );
    data->PRICE=price;
    head=data;
    head->next=NULL;
}

void search_b(void)
{
    bool found=false;
    head=backup_header;

    printf("Search Mode:\n");
    printf("Input ISBN:");
    uint64_t isbn;
    scanf("%lu", &isbn);


    while(1)
    {
        if(head->next==NULL)
        {
            if(isbn==head->ISBN)
            {
                printf("Found!!!\n");
                printf("ISBN\t\tBookName\t\tPrice\n");
                printf("%lu\t\t%s\t\t%u\n\n",head->ISBN,head->BookName,head->PRICE);
                found=true;
                head=head->next;
                break;
            }
            printf("Stopping traversing...\n");
            if(found==false)
            {
                printf("Not found!!!\n");
            }
            break;
        }
        else
        {
            if(isbn==head->ISBN)
            {
                printf("Found!!!\n");
                printf("ISBN\t\tBookName\t\tPrice\n");
                printf("%lu\t\t%s\t\t%u\n\n",head->ISBN,head->BookName,head->PRICE);
                found=true;
                head=head->next;
                break;
            }
            else
            {
                head=head->next;
                continue;
            }
        }
    }
}

void delete_b(void)
{
    head=backup_header;
    uint64_t isbn=0;
    bool exist=false;
    printf("Input ISBN:");
    scanf("%lu",&isbn);

    while(1)
    {
        if(head->ISBN==isbn)
        {
            void *tmp=head;
            head=head->next;
            free(tmp);
            exist=true;
            backup_header=head;
            break;
        }
        if(head->next->ISBN==isbn)
        {
            void *tmp=head->next->next;
            free(head->next);
            head->next=tmp;
            exist=true;
            break;
        }
        else
        {
            if(head->next==NULL)
            {
                break;
            }
            head=head->next;
        }
    }

    if(exist==true)
    {
        printf("Found!!!\nFinished to delete\n");
    }
    else
    {
        printf("Not found!!!\n");
    }

}

void print_all(void)
{
    head=backup_header;
    printf("ISBN\t\tBookName\t\tPrice\n");
    while(1)
    {
        if(head->next==NULL)
        {
            printf("%lu\t%-2s\t\t%6u\n",head->ISBN,head->BookName,head->PRICE);
            printf("Stopping traversing...\n");
            break;
        }
        else
        {
            printf("%lu\t%-2s\t\t%6u\n",head->ISBN,head->BookName,head->PRICE);
            head=head->next;
        }
    }
}

