#include <stdio.h>
#include <stdlib.h>

typedef long T;

typedef struct SortedList {
  T value;
  
  struct SortedList* next;
} SortedList;

void init(SortedList** list)
{
    list = (SortedList **) malloc (sizeof(SortedList*));
    list=NULL;
    printf("%p\n", list);
}
void isEmpty(SortedList** list)
{
    printf("%p\n", list);

    if(list == NULL) printf("List is empty\n");
}
int main()  
{
    SortedList **list;
    init(list);
    printf("Initialization with succes\n");
    isEmpty(list);

    return 0;
}