#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
ou are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.


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

struct ListNode *delete(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *temp = head;
    struct ListNode *slow = head;
    if(head->next==NULL)
    {
        return NULL;
    }
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while(temp->next!=slow)
    {
        temp=temp->next;
    }
    temp->next=slow->next;
    free(slow);
    slow=NULL;
   
    return head;
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

    head->val = 1;
    head->next = NULL;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
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
    // printf("\n");
    q = delete(head);

    traversal(q);



    // arr = next(head, &size);
    // printf("%d\n", size);
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);
    // free(arr);

    free(head2);
    free(second2);
    free(third2);

    return 0;
}