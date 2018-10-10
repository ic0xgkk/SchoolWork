/*
Ice Cream <i@xuegao.hk>
This is an example program which written by Ice Cream.It only can be used in learning and watering.
You can catch me on my GayHub https://github.com/ic0xgkk
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
//uint32_t BookNum=0;
struct Books *head=NULL;
bool finished_loading=false;

void insert_b(uint64_t isbn, char bookname[], uint32_t price);
void search_b(void);
void delete_b(void);
void print_all(void);
void test(void);

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
		//printf("%s", tmp);
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
            case 5:test();break;
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

void test(void)
{
    while(1)
    {
        if(head==NULL)
        {
            break;
        }
        head=head->next;
    }
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
    uint32_t id=0;
    bool exist=false;
    printf("Input ID:");
    scanf("%u",&id);

    void *p=head;
/*
    for(uint32_t i=0;i<BookNum;i++)
    {
        if(head==NULL)
        {
            printf("BookList is blank\n");
            return NULL;
        }
        if(head->next->ID==id)
        {
            printf("Found it! \n");
            free(head->next);
            exist=true;
            break;
        }
        head=head->next;
    }
    if(exist==false)
    {
        printf("Not Found!\n");
    }
    head=p;
    */
}

void print_all(void)
{
    head=backup_header;
    printf("ISBN\t\tBookName\t\tPrice\n");
    while(1)
    {
        if(head->next==NULL)
        {
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

