void showmth(int m)
{
    struct list *ptr;
    ptr=start;
    for(int i=1;i<count-m-1;i++)
    {
        ptr=ptr->next;
    }
    printf("data at %d from last id : ", ptr->info);
}