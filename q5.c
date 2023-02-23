void removeloop()
{
    struct list *ptr, *ptr2;
    ptr=start;
    ptr2=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    while(ptr2->next!=NULL)
    {
        if(ptr==ptr2)
        {
            ptr->next=NULL;
            break;
        }
        pr2=ptr2->next;
    }
}