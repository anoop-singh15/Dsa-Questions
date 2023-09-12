#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.
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

int components(struct ListNode *head, int *nums, int numsSize)
{
    struct ListNode *temp = head;
    struct ListNode *cons = NULL;
    int *arr;
    int ans = 0;
    int c = 0;
    if (head->next == NULL)
    {
        return 1;
    }
    while (temp)
    {
        c++;
        temp = temp->next;
    }
    arr = (int *)calloc(c, sizeof(int));
    temp = head;
    for (int i = 0; i < c; i++)
    {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < numsSize; i++)
    {
        arr[nums[i]] = 1;
    }
    for (int i = 0; i < c; i++)
    {
        printf("%d ", arr[i]);
    }

    while (temp)
    {
        if (arr[temp->val] == 1)
        {
            cons = temp;
            while (cons && arr[cons->val] != 0)
            {

                cons = cons->next;
            }
            ans++;
            temp = cons;
        }
        else
        {
            temp = temp->next;
        }
    }
    printf("\n");
    return ans;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = NULL;
    int arr[] = {0, 1, 3};
    int n = 3;
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
    printf("%d\n", components(head, arr, n));

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    return 0;
}