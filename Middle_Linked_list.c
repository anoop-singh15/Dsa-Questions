#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;

        count++;
    }

    if (count % 2 == 0)
    {
        count++;
    }
    count /= 2;

    while (count > 0)
    {
        head = head->next;
        count--;
    }
    return head;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp2;

    head->val = 0;
    head->next = second;

    second->val = 17;
    second->next = third;

    third->val = 1;
    third->next = NULL;

    temp2 = middleNode(head);
    printf("%d\n", temp2->val);

    free(head);
    free(second);
    free(third);

    return 0;
}