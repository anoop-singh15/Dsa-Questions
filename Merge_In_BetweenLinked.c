#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


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

struct ListNode *merge(struct ListNode *list1, int a, int b, struct ListNode *list2)
{
    struct ListNode *temp1 = list1;
    struct ListNode *temp2 = list1;
    struct ListNode *q = list2;
    for (int i = 0, j = 0; i < a - 1, j < b; i++, j++)
    {
        if (j < b)
        {
            temp2 = temp2->next;
        }
        if (i < a - 1)
        {
            temp1 = temp1->next;
        }
    }
    printf("%d %d\n", temp1->val, temp2->val);
    while (q->next)
    {
        q = q->next;
    }
    temp1->next = list2;
    q->next = temp2->next;
    return list1;
}

int main()
{
    int a, b;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = NULL;

    head->val = 0;
    head->next = second;

    second->val = 1;
    second->next = third;

    third->val = 2;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = fifth;

    fifth->val = 4;
    fifth->next = NULL;

    head2->val = 10000;
    head2->next = second2;

    second2->val = 100001;
    second2->next = third2;

    third2->val = 100002;
    third2->next = fourth2;

    fourth2->val = 100003;
    fourth2->next = fifth2;

    fifth2->val = 100004;
    fifth2->next = NULL;

    // Both head1 and head2 traversal
    traversal(head);
    printf("\n");
    traversal(head2);
    printf("\n");

    // Main logic
    a = 3, b = 4;
    q = merge(head, a, b, head2);

    printf("\n");
    traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);
    free(head2);
    free(second2);
    free(third2);
    free(fourth2);
    free(fifth2);

    return 0;
}