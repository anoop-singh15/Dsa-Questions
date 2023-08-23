#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 
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


// MY ORIGINAL SOLUTION BEATS 68.47% USER IN RUNTIME AND 5.41% IN MEMORY
struct ListNode *add(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *temp1 = l1;
    struct ListNode *temp_1 = l1;
    struct ListNode *temp2 = l2;
    struct ListNode *temp_2 = l2;
    struct ListNode *p = NULL;
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    struct stack *s2 = (struct stack *)malloc(sizeof(struct stack));
    struct stack *s3 = (struct stack *)malloc(sizeof(struct stack));
    struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
    q->val = -1;
    q->next = NULL;

    int sum;
    int carry = 0;
    int count1 = 0;
    int count2 = 0;

    s1->size = 120;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));

    s2->size = 120;
    s2->top = -1;
    s2->arr = (int *)malloc(s2->size * sizeof(int));

    s3->size = 120;
    s3->top = -1;
    s3->arr = (int *)malloc(s3->size * sizeof(int));

    while (1)
    {
        if (temp1)
        {
            count1++;
            push(s1, temp1->val);
            temp1 = temp1->next;
        }
        if (temp2)
        {
            count2++;
            push(s2, temp2->val);
            temp2 = temp2->next;
        }
        if (!temp1 && !temp2)
        {
            break;
        }
    }

    while (1)
    {
        if (isEmpty(s1) != 1 && isEmpty(s2) != 1)
        {
            sum = (stackTop(s1) + stackTop(s2) + carry);
            push(s3, sum % 10);
            carry = (sum) / 10;
            pop(s1);
            pop(s2);
        }
        if (isEmpty(s1) != 1 && isEmpty(s2) == 1)
        {
            push(s3, (stackTop(s1) + carry) % 10);
            carry = (stackTop(s1) + carry) / 10;
            pop(s1);
        }
        if (isEmpty(s1) == 1 && isEmpty(s2) != 1)
        {
            push(s3, (stackTop(s2) + carry) % 10);
            carry = (stackTop(s2) + carry) / 10;
            pop(s2);
        }

        if (isEmpty(s1) == 1 && isEmpty(s2) == 1)
        {
            if (carry != 0)
            {
                push(s3, carry);
            }
            break;
        }
    }

    if (count1 <= count2)
    {
        temp_1 = l2;
    }
    else
        temp_1 = l1;
    while (temp_1)
    {

        temp_1->val = stackTop(s3);
        pop(s3);
        temp_1 = temp_1->next;
    }

    if (isEmpty(s3) != 1)
    {
        q->val = stackTop(s3);
        if (count2 >= count1)
            p = l2;
        else
            p = l1;

        while (p->next)
        {
            p = p->next;
        }
        p->next = q;
    }
    if (count1 > count2)
        return l1;
    return l2;
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

    struct ListNode *q = NULL;

    head->val = 6;
    head->next = second;

    second->val = 4;
    second->next = third;

    third->val = 5;
    third->next = NULL;

    fourth->val = 9;
    fourth->next = fifth;

    fifth->val = 9;
    fifth->next = NULL;

    head2->val = 3;
    head2->next = second2;

    second2->val = 8;
    second2->next = third2;

    third2->val = 8;
    third2->next = NULL;

    traversal(head);
    printf("\n");
    traversal(head2);
    printf("\n");

    q = add(head, head2);
    traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    free(head2);
    free(second2);
    free(third2);

    return 0;
}