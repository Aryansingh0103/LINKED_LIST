#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next, *arbit;
};
  
   struct Node* SortedMerge(struct Node* a, struct Node* b);
   void FrontBackSplit(struct Node* source,
   struct Node** frontRef, struct Node** backRef);
  
void MergeSort(struct Node** headRef)
{
    struct Node* head = *headRef;
    struct Node* a, *b;
  
    if ((head == NULL) || (head->arbit == NULL))
        return;
 
    FrontBackSplit(head, &a, &b);
  
    MergeSort(&a);
    MergeSort(&b);
  
    *headRef = SortedMerge(a, b);
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b==NULL)
        return (a);
  
    if (a->data <= b->data)
    {
        result = a;
        result->arbit = SortedMerge(a->arbit, b);
    }
    else
    {
        result = b;
        result->arbit = SortedMerge(a, b->arbit);
    }
  
    return (result);
}
  
void FrontBackSplit(struct Node* source,
                    struct Node** frontRef, struct Node** backRef)
{
    struct Node* fast, *slow;
  
    if (source==NULL || source->arbit==NULL)
    {
 
        *frontRef = source;
        *backRef = NULL;
        return;
    }
  
    slow = source,  fast = source->arbit;
  
    while (fast != NULL)
    {
        fast = fast->arbit;
        if (fast != NULL)
        {
            slow = slow->arbit;
            fast = fast->arbit;
        }
    }
  
    *frontRef = source;
    *backRef = slow->arbit;
    slow->arbit = NULL;
}

void push(struct Node** head_ref, int new_data)
{
  
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
  
    new_node->next = (*head_ref);
  
    new_node->arbit = NULL;
  
    (*head_ref)    = new_node;
}

void printListafter(struct Node *node, struct Node *anode)
{
    printf("Traversal using Next Pointer\n");
    while (node!=NULL)
    {
        printf("%d, ", node->data);
        node = node->next;
    }
  
    printf("\nTraversal using Arbit Pointer\n");
    while (anode!=NULL)
    {
        printf("%d, ", anode->data);
        anode = anode->arbit;
    }
}

struct Node* populateArbit(struct Node *head)
{

    struct Node *temp = head;
    while (temp != NULL)
    {
        temp->arbit = temp->next;
        temp = temp->next;
    }

    MergeSort(&head);
  
    return head;
}
  
int main()
{
    
    struct Node* head = NULL;
  
    push(&head, 3);
    push(&head, 2);
    push(&head, 10);
    push(&head, 5);
  
    struct Node *ahead = populateArbit(head);
  
    printf("\nResult Linked List is: \n");
    printListafter(head, ahead);
  
    getchar();
    return 0;
}