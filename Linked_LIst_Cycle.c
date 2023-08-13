#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
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

bool hasCycle(struct ListNode *head)
{
    struct ListNode *headFTemp = head;
    struct ListNode *headSTemp2 = head;

    if (head == NULL)
    {
        return false;
    }
    if (head->next == NULL)
    {
        return false;
    }

    while(headFTemp!=NULL && headFTemp->next!=NULL)
    {
        headSTemp2=headSTemp2->next;
        headFTemp=headFTemp->next->next;
        if(headFTemp==headSTemp2)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = 3;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 5;
    third->next = fourth;

    fourth->val = 0;
    fourth->next = NULL;

    fifth->val = 1;
    fifth->next = NULL;

    // traversal(head);
    // printf("\n");
    printf("Result--->%d\n", hasCycle(head));

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}