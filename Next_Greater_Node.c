#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.


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

void pop(struct stack *ptr)
{
    if (!isEmpty(ptr))
    {
        ptr->top--;
    }
}

void push(struct stack *ptr, int val)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void stackTraversal(struct stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

void traversal(struct ListNode *ptr)
{
    struct ListNode *temp = ptr;
    while (temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

struct ListNode *reverse(struct ListNode *ptr)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = ptr;
    struct ListNode *curr_next = NULL;

    while (current)
    {

        curr_next = current->next;
        current->next = prev;
        prev = current;
        current = curr_next;
    }

    return prev;
}

int *next(struct ListNode *head, int *returnSize)
{
    int *rarr = (int *)malloc(10000 * sizeof(int));
    rarr[0] = 0;
    struct ListNode *temp = NULL;
    int a = 0;
    int i;
    int j;
    int temp_val;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 1000;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top = -1;
    s->arr[0] = 0;

    temp = reverse(head);
    while (temp)
    {
        if (isEmpty(s))
        {
            rarr[a++] = 0;
            push(s, temp->val);
            temp = temp->next;
        }
        else if (stackTop(s) > temp->val)
        {
            rarr[a++] = stackTop(s);
            push(s, temp->val);
            temp = temp->next;
        }
        else
        {
            pop(s);
        }
    }
    i = 0;
    j = a - 1;
    while (i < j)
    {
        temp_val = rarr[i];
        rarr[i] = rarr[j];
        rarr[j] = temp_val;
        i++;
        j--;
    }

    *returnSize = a;
    return rarr;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    // struct ListNode *q = NULL;
    int *arr;
    int size;

    head->val = 2;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 2;
    third->next = fourth;

    fourth->val = 2;
    fourth->next = fifth;

    fifth->val = 2;
    fifth->next = NULL;

    head2->val = 3;
    head2->next = second2;

    second2->val = 8;
    second2->next = third2;

    third2->val = 8;
    third2->next = NULL;

    traversal(head);
    printf("\n");
    // traversal(head2);
    // printf("\n");

    // q = next(head);
    arr = next(head, &size);
    printf("%d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    // free(q);
    free(arr);

    free(head2);
    free(second2);
    free(third2);

    return 0;
}