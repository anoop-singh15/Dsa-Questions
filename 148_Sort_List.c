#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the head of a linked list, return the list after sorting it in ascending order.
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

struct ListNode * sort(struct ListNode *head)
{
    
}


int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = NULL;
    
    head->val = 0;
    head->next = second;

    second->val = 1;
    second->next = third;

    third->val = 2;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = NULL;

    fifth->val = 4;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    q = sort(head);
    traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    return 0;
}