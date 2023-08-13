#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

void traversal(struct ListNode *ptr)
{
    struct ListNode *temp = ptr;
    while (temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int hcf(int x,int y)
{
    if(y!=0)
        return hcf(y,x%y);
    return x;    
}

struct ListNode *insert(struct ListNode *head)
{
    struct ListNode *result=head;
    struct ListNode *head_next=head->next;

    if(head==NULL)
    {
        return head;
    }
    
    while(head_next)
    {
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=hcf(head->val,head_next->val);
        temp->next=head_next;
        head->next=temp;
        head=head_next;
        head_next=head->next;    
    }
    return result;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = NULL;
    int val = 3;

    head->val = 18;
    head->next = second;
   

    second->val = 6;
    second->next = third;

    third->val = 10;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = NULL;

    fifth->val = 1;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    // printf("%d\n",hcf(3,2));
    q = insert(head);
    traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    return 0;
}