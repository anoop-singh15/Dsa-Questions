#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct stack
{
    int size;
    int top;
    int *arr;
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

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr)
{
    if (!isEmpty(ptr))
    {
        ptr->top--;
    }
}

void stackTraversal(struct stack *ptr)
{
    for (int i = 0; i < ptr->top; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

struct ListNode *remove_list(struct ListNode *head)
{
    int max = 0;
    struct ListNode *prev = NULL;
    struct ListNode *result = NULL;
    struct ListNode *temp2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp2->val = -1;
    temp2->next = NULL;
    struct ListNode *temp3 = temp2;

    struct ListNode *temp = head;
    struct ListNode *temp_next = NULL;
    while (temp)
    {
        temp_next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp_next;
    }
    head = prev;
    while (head)
    {
        if (max <= head->val)
        {
            max = head->val;
            temp3->next = head;
            temp3 = head;
        }
        head = head->next;
    }
    temp3->next = NULL;
    result = temp2->next;
    free(temp2);
    temp2 = NULL;

    temp = result;
    prev = NULL;

    while (temp)
    {
        temp_next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp_next;
    }
    return prev;
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

    head->val = 5;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 13;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = fifth;

    fifth->val = 8;
    fifth->next = NULL;

    // Both head1 and head2 traversal
    traversal(head);
    printf("\n");

    // Main logic
    a = 2;
    q = remove_list(head);

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