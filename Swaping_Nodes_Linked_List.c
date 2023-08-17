#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
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

struct ListNode *swap(struct ListNode *head, int k)
{
    int count = 1;
    int temp;
    struct ListNode *left = head;
    struct ListNode *curr = head;
    struct ListNode *right = head;
    while (curr)
    {
        if (count < k)
            left = left->next;
        if (count > k)
            right = right->next;
        curr = curr->next;
        count++;
    }
    temp = left->val;
    left->val = right->val;
    right->val = temp;

    return head;
}

int main()
{
    int a;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = NULL;

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = NULL;

    fourth->val = 6;
    fourth->next = NULL;

    fifth->val = 5;
    fifth->next = NULL;

    // Both head1 and head2 traversal
    traversal(head);
    printf("\n");

    // Main logic
    a = 2;
    q = swap(head, a);

    printf("\n");
    traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    return 0;
}