#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
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

struct ListNode *duplicate(struct ListNode *head)
{
    struct ListNode *result = head;
    struct ListNode *temp = result->next;
    if(head==NULL)
        return head;
    while (temp)
    {
       while(result->val==temp->val)
       {
            temp=temp->next;
            if(temp==NULL)
            {
                break;
            }
       }
       result->next=temp;
       result=temp;
       if(result==NULL)
       {
        break;
       }
       temp=temp->next;
    }
    free(temp);
    return head;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q2 = NULL;

    head->val = 1;
    head->next = second;

    second->val =1;
    second->next = third;

    third->val = 2;
    third->next = fourth;

    fourth->val =3;
    fourth->next = fifth;

    fifth->val = 3;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    q2 = duplicate(head);
    traversal(q2);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q2);

    return 0;
}