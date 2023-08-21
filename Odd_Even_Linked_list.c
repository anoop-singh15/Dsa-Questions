#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
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

struct ListNode *oddEven(struct ListNode *head)
{
    struct ListNode *odd = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *even = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *odd_next = odd;
    struct ListNode *result = NULL;
    struct ListNode *even_next = even;
    odd->val = -1;
    odd->next = NULL;
    even->val = -1;
    even->next = NULL;

    while (head && head->next)
    {

        odd_next->next = head;
        odd_next = odd_next->next;

        head = head->next;

        even_next->next = head;
        even_next = even_next->next;
        head = head->next;
    }
    even_next->next = NULL;
    even_next = even_next->next;
    if (head)
    {
        odd_next->next = head;
        odd_next = odd_next->next;
    }

    odd_next->next = even->next;

    result = odd->next;
    free(odd);
    free(even);
    odd = even = NULL;

    return result;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q2 = NULL;

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
    fourth->next = NULL;

    fifth->val = 5;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    q2 = oddEven(head);
    traversal(q2);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q2);

    return 0;
}