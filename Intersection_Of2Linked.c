#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
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
// Program to reverse LL
struct ListNode *revlist(struct ListNode *headA)
{
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    while (headA != NULL)
    {
        next = headA->next;
        headA->next = prev;
        prev = headA;
        headA = next;
    }
    return prev;
}

struct ListNode *intersect(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *tempa = headA;
    struct ListNode *tempb = headB;

    while (tempa != tempb)
    {
        if (tempa == NULL)
        {
            tempa = headB;
        }
        if (tempb == NULL)
        {
            tempb = headA;
        }
        if (tempa == tempb)
        {
            break;
        }
        if (tempa == NULL && tempb == NULL)
        {
            break;
        }
        // printf("\n%d %d\n", tempa->val, tempb->val);
        tempa = tempa->next;
        tempb = tempb->next;
    }
    
    return tempa;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *q2 = NULL;

    head->val = 2;
    head->next = second;

    second->val = 6;
    second->next = third;

    third->val = 4;
    third->next = NULL;

    fourth->val = 4;
    fourth->next = fifth;

    fifth->val = 5;
    fifth->next = NULL;

    head2->val = 1;
    head2->next = second2;

    second2->val = 5;
    second2->next = NULL;

    third2->val = 8;
    third2->next = NULL;

    traversal(head);
    printf("\n");

    traversal(head2);

    q2 = intersect(head, head2);
    printf("\n");
    traversal(q2);

    free(head);
    free(second);
    free(third);

    free(head2);
    free(second2);
    free(third2);
    free(q2);

    return 0;
}