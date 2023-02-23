#include<stdio.h>
#include<stdlib.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
struct Node
{
    int data;
    struct Node* next;
};

int countCommon(struct Node *a,struct Node *b)
{
    int count = 0;
 
    // loop to count common in the list starting
    for (; a && b; a = a->next, b = b->next)
 
        if (a->data == b->data)
            ++count;
        else
            break;
 
    return count;
}
 
// Returns length of the longest palindrome
// sublist in given list
int maxPalindrome(struct Node *head)
{
    int result = 0;
    struct Node *prev = NULL;
    struct Node *curr = head;

    while (curr)
    {
        // The sublist from head to current
        // reversed.
        struct Node *next = curr->next;
        curr->next = prev;
 
        // check for odd length palindrome
        // by finding longest common list elements
        // beginning from prev and from next (We
        // exclude curr)
        result = max(result,
                     2*countCommon(prev, next)+1);
 
        // check for even length palindrome
        // by finding longest common list elements
        // beginning from curr and from next
        result = max(result,
                     2*countCommon(curr, next));
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
    return result;
}
 
struct Node *newNode(int key)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
int main()
{
    /* Let us create a linked lists to test
       the functions */
   
    struct Node *head = newNode(2);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(15);
 
    int ans = maxPalindrome(head);
    printf("%d \n",ans);
    return 0;
}