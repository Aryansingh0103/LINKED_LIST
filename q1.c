#include <stdio.h>
#include <stdlib.h>
struct list
{
    int info;
    struct list *next;
};
struct list *start = NULL;
void addlast(int item)
{
    struct list *ptr1;
    ptr1 = (struct list *)malloc(sizeof(struct list));
    ptr1->info = item;
    ptr1->next = NULL;
    if (start == NULL)
    {
        start = ptr1;
    }
    else
    {
        struct list *ptr2;
        ptr2 = start;
        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr1;
    }
}
void addfirst(int item)
{
    struct list *ptr1;
    ptr1=(struct list *)malloc(sizeof(struct list));
    ptr1->info=item;
    if (start == NULL)
    {
        ptr1->next=NULL;
        start=ptr1;
    }
    else
    {
        ptr1->next = start;
        start = ptr1;
    }
}
void addpost(int item, int k)
{
    int i;
    struct list *ptr, *ptr1;
    ptr1=(struct list *)malloc(sizeof(struct list));
    ptr = start;
    for (i = 1; i < k-1 ; i++)
    {
        ptr = ptr->next;
    }
    ptr1->info = item;
    ptr1->next = ptr->next;
    ptr->next = ptr1;
}
void checklist()
{
    if (start == NULL)
    {
        printf("empty list \n");
    }
    else
    {
        printf("list not empty");
    }
}
void deletelast()
{
    int num = -1;
    if (start == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        struct list *ptr, *pre;
        ptr = start;
        while (ptr->next != NULL)
        {
            pre = ptr;
            ptr = ptr->next;
        }
        num = ptr->info;
        pre->next = NULL;
        free(ptr);
        printf("the deleted value is : %d", num);
    }
}
void deletefirst()
{
    int num = -1;
    if (start == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        struct list *ptr;
        ptr = start;
        start = start->next;
        num = ptr->info;
        free(ptr);
        if (num != -1)
        {
            printf("the deleted value is : %d", num);
        }
    }
}
void show()
{
    struct list *p;
    p = start;
    printf("START->");
    while (p->next != NULL)
    {
        printf("%d->", p->info);
        p = p->next;
    }
    printf("%d->", p->info);
    printf("NULL");
}
void addl()
{
    int num;
    printf("\nenter the value to be added at last : ");
    scanf("%d", &num);
    addlast(num);
    printf("\nadded");
}
void addf()
{
    int num;
    printf("enter the value to be added at first : ");
    scanf("%d", &num);
    addfirst(num);
    printf("\nadded");
}
void addp()
{
    int num, a;
    printf("enter the value to be added : ");
    scanf("%d", &num);
    printf("enter the position of the node to be added : ");
    scanf("%d", &a);
    addpost(num, a);
    printf("\nadded");
}
void nodecount()
{
    int count = 0;
    struct list *p;
    p = start;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    printf("\ntotal no. of nodes are : %d", count+1);
}
void search(int num)
{
    struct list *p;
    int flag = 0;
    p = start;
    while (p->next != NULL)
    {
        if (p->info == num)
        {
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 1)
    {
        printf("\npresent in the list ");
    }
    else
    {
        printf("not present in list");
    }
}
void main()
{
    int op, c;
    do
    {
        printf("\nlinked list operations");
        printf("\n1 to add at last");
        printf("\n2 to add at first");
        printf("\n3 to add at position");
        printf("\n4 to delete last node");
        printf("\n5 to to delete first node");
        printf("\n6 to show list");
        printf("\n7 to view no. of nodes ");
        printf("\n8 to search a no. in list");
        printf("\n9 to check list empty or not");
        printf("\n0 to exit");
        printf("\nenter your choice : ");
        scanf("%d", &op);
        if (op == 1)
            addl();
        else if (op == 2)
            addf();
        else if (op == 3)
            addp();
        else if (op == 4)
            deletelast();
        else if (op == 5)
            deletefirst();
        else if (op == 6)
            show();
        else if (op == 7)
            nodecount();
        else if (op == 8)
        {
            printf("\nenter the no. to search : ");
            scanf("%d", &c);
            search(c);
        }
        else if (op == 9)
            checklist();

    } while (op != 0);
}