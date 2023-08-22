#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

*/

struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
    struct TreeNode *next;
};

struct stack
{
    int size;
    int top;
    int *arr;
};

void preorder(struct TreeNode *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->val);
        preorder(ptr->left);

        preorder(ptr->right);
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

struct TreeNode *connect(struct TreeNode *root)
{
    struct TreeNode *temp = root;
  
    struct TreeNode *curr = NULL;
    while (temp)
    {
       curr=temp;
       while(curr)
       {
            if(curr->left)
            {
                curr->left->next=curr->right;

            }
            if(curr->right)
            {
                if(curr->next)
                {
                    curr->right->next=curr->next->left;

                }
                else
                {
                    curr->right->next=NULL;
                }
            }
            curr=curr->next;
       }
       temp=temp->left;

    }
    return root;
}

int main()
{

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *second = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *secondl = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *secondr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *third = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *thirdl = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *thirdr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *q = NULL;

    root->val = 1;
    root->left = second;
    root->right = third;
    root->next = NULL;

    second->val = 2;
    second->left = secondl;
    second->right = secondr;
    second->next = NULL;

    secondl->val = 4;
    secondl->left = NULL;
    secondl->right = NULL;
    secondl->next = NULL;

    secondr->val = 5;
    secondr->left = NULL;
    secondr->right = NULL;
    secondr->next = NULL;

    third->val = 3;
    third->left = thirdl;
    third->right = thirdr;
    third->next = NULL;

    thirdl->val = 6;
    thirdl->left = NULL;
    thirdl->right = NULL;
    thirdl->next = NULL;

    thirdr->val = 7;
    thirdr->left = NULL;
    thirdr->right = NULL;
    thirdr->next = NULL;

    // Both head1 and head2 traversal
    preorder(root);
    q = connect(root);
    printf("\n");
    preorder(q);

    free(root);
    free(second);
    free(third);

    free(secondl);
    free(secondr);
    free(third);
    free(thirdl);
    free(thirdr);

    return 0;
}