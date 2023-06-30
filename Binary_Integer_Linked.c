#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

int getDec(struct ListNode *head)
{
    int count=0;
    int arr[50];
    int a;
    int fac=1;
    long int ret=0;
    struct ListNode *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    a=count;
    while(head!=NULL)
    {
        arr[count-1]=head->val;
        head=head->next;
        count--;
    }

    for(int i=0;i<a;i++)
    {
        ret=ret+arr[i]*fac;
        fac=fac*2;

    }
    return ret;
   
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = 0;
    head->next = second;

    second->val =0;
    second->next = third;

    third->val = 1;
    third->next = NULL;

    printf("%d\n", getDec(head));

    free(head);
    free(second);
    free(third);

    return 0;
}