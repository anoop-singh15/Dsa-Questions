#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.
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

struct ListNode *merge(struct ListNode *head)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *result = NULL;
    struct ListNode *temp_next = NULL;
    temp->val = -1;
    temp->next = NULL;
    temp_next = temp;
    int sum = 0;
    bool count = true;

    while (head)
    {

        if (head->val == 0 && count == true)
        {
            count = false;
        }
        else if (head->val != 0 && count == false)
        {
            sum = sum + head->val;
        }
        else if (head->val == 0 && count == false)
        {
            temp_next->next = head;
            head->val = sum;
            temp_next = head;
            sum=0;
        }
        head = head->next;
    }
    if (head == NULL)
    {
        temp_next->next = NULL;
        temp_next = NULL;
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

    head->val = 0;
    head->next = second;

    second->val = 3;
    second->next = third;

    third->val = 0;
    third->next = fourth;

    fourth->val = 9;
    fourth->next = fifth;

    fifth->val = 0;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    q = merge(head);
    traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    return 0;
}