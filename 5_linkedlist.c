#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

void removeLoop(struct ListNode *head)
{
    // Initialize ptr1 and ptr2 to head node.
    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = head;
    // Boolean to check if there a loop exists in the given Linked List.
    int flag = 0;
    // Traverse the list until ptr2 or ptr2.next is null.
    while (ptr2 != NULL && ptr2->next != NULL)
    {
        // Move ptr1 forward by one node.
        ptr1 = ptr1->next;
        // Move ptr2 forward by two nodes.
        ptr2 = ptr2->next->next;
        if (ptr1 == ptr2)
        {
            flag = 1;
            break;
        }
    }
    // When there is a loop in the Linked List.
    if (flag)
    {
        // Assign head to ptr1.
        ptr1 = head;
        // Loop until next of ptr1 and ptr2 are not equal.
        while (ptr1->next != ptr2->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // Make next of ptr2 that is last node of Linked List NULL.
        ptr2->next = NULL;
    }
}

int main()
{
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 2;
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    l1->val = 8;
    head->next = l1;
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l2->val = 3;
    l1->next = l2;
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    l3->val = 5;
    l2->next = l3;
    struct ListNode *l4 = malloc(sizeof(struct ListNode));
    l4->val = 10;
    l3->next = l4;
    l4->next = l2;
    removeLoop(head);
    while (head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL");
    return 0;
}