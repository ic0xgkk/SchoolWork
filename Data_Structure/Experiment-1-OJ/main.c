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
    float PRICE;
    struct Books *next;
};
void *backup_header=NULL;
struct Books *head=NULL;

void insert_b(uint64_t isbn, char bookname[], float price);
void print_all(void);

int main()
{
    while(1)
    {
        uint64_t isbn;
        float price;
        char bookname[128];
		scanf("%lu%s%f", &isbn, bookname, &price);
		if(isbn==0)
            break;
        else
        {
            insert_b(isbn, bookname, price);
            continue;
        }
    }
    print_all();
}

void insert_b(uint64_t isbn, char bookname[], float price)
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

    if(head==NULL)
        head=data;

    if(backup_header==NULL)
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

void print_all(void)
{
    head=backup_header;
    uint16_t num=0;
    while(1)
    {
        if(head->next==NULL)
        {
            num++;
            break;
        }
        else
        {
            num++;
            head=head->next;
        }
    }
    printf("%u\n",num);

    head=backup_header;
    while(1)
    {
        if(head->next==NULL)
        {
            printf("%lu %s %.2f\n",head->ISBN,head->BookName,head->PRICE);
            break;
        }
        else
        {
            printf("%lu %s %.2f\n",head->ISBN,head->BookName,head->PRICE);
            head=head->next;
        }
    }
}

