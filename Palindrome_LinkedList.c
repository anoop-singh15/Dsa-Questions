#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct stack
{
    int *arr;
    int size;
    int top;
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

bool isEmpty(struct stack * ptr)
{
    if(ptr->top==-1)
    {
        return true;
    }
    return false;
}

bool isFull(struct stack * ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return true;
    }
    return false;
}

int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

void push(struct stack * ptr,int data)
{
    if(!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

bool pop(struct stack*ptr)
{
    if(!isEmpty(ptr))
    {
        ptr->top--;
        return true;
    }
    return false;
}

int stackbottom(struct stack * ptr)
{
    return ptr->arr[0];
}

bool palindrome(struct ListNode *head)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size=100;
    st->arr=(int *)malloc(st->size * sizeof(int));
    st->arr[0]=-1;
    st->top=-1;
   

    if(head->next==NULL)
        return true;
    while(head)
    {
        if(head->val==stacktop(st))
        {
            pop(st);
        }
        else
        {
            push(st,head->val);
        }
       
        head=head->next;
    }
    if(isEmpty(st) || (st->top==2 && stacktop(st)==stackbottom(st)))
    {
        return true;
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
    // struct ListNode *q2 = NULL;

    head->val = 1;
    head->next = second;

    second->val = 3;
    second->next = third;

    third->val = 3;
    third->next = NULL;

    fourth->val = 1;
    fourth->next = NULL;

    fifth->val = 2;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    printf("%d\n", palindrome(head));

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}