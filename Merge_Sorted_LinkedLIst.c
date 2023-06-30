#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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

struct ListNode *insert(struct ListNode *ptr, int data)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = NULL;
    temp->val = data;
    temp->next = NULL;

    if (ptr == NULL)
    {
        ptr = temp;
    }
    else
    {
        q = ptr;
        while (q->next != NULL)
        {
            q = q->next;
        }

        q->next = temp;
    }

    return ptr;
}

struct ListNode *sortmerge(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *p = NULL;

    if (list1 == NULL && list2 != NULL)
    {
        p = list2;
    }
    if (list1 != NULL && list2 == NULL)
    {
        p = list1;
    }

    else
    {
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val == list2->val)
            {
                p = insert(p, list2->val);
                list1 = list1->next;
            }
            if (list1->val > list2->val)
            {
                p = insert(p, list2->val);
                list2 = list2->next;
            }
            else if(list1->val < list2->val)
            {
                p = insert(p, list1->val);
                list1=list1->next;
            }
            else 
            {
                  p = insert(p, list1->val);
                list1=list1->next;
            }
        }
    }
    return p;
}
int main()
{

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *q2;

    head->val = 5;
    head->next = NULL;

    second->val = 2;
    second->next = third;

    third->val = 4;
    third->next = NULL;

    head2->val = 1;
    head2->next = second2;

    second2->val = 3;
    second2->next = third2;

    third2->val = 4;
    third2->next = NULL;

    traversal(head);
    printf("\n");

    traversal(head2);
    q2 = sortmerge(head, head2);

    printf("\n");
    traversal(q2);

    free(head);
    free(second);
    free(third);

    free(head2);
    free(second2);
    free(third2);

    return 0;
}