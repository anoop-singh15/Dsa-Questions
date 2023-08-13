#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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

struct ListNode *removeelement(struct ListNode *head, int val)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp_next = temp;
    struct ListNode *result = NULL;

    temp->next = NULL;
    temp->val = -10;

    while (head)
    {
        if (head->val != val )
        {
            temp_next->next = head;

            temp_next = temp_next->next;
        }
        head = head->   next;
       
    }
    if(head==NULL)
    {
        temp_next->next=head;
    }

    result = temp->next;
    free(temp);
    temp = NULL;

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

    head->val = 3;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 5;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = NULL;

    fifth->val = 1;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    q = removeelement(head, val);
    traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    return 0;
}