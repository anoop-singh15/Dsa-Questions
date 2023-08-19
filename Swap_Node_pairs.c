#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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

struct ListNode *swap(struct ListNode *head)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp_next = temp;
    struct ListNode *result = NULL;
    struct ListNode *p = head;
    struct ListNode *q = NULL;
    struct ListNode *temp2 = NULL;
    struct ListNode *p2 = head;
    temp->val = -1;
    temp->next = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (p != NULL && p->next != NULL)
    {

        q = p->next;
        temp2 = q->next;
        temp_next->next = q;

        temp_next = temp_next->next;
        q->next = p;
        temp_next = temp_next->next;
        p->next = temp2;

        p = temp2;
    }

    result = temp->next;
    free(temp);
    temp = NULL;

    return result;
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
    fourth->next = NULL;

    fifth->val = 8;
    fifth->next = NULL;

    // Both head1 and head2 traversal
    traversal(head);
    printf("\n");

    // Main logic
    a = 2;
    q = swap(head);

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