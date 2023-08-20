#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

-------------->MORRIS TRAVERSAL
               TIME COMP. =O(N)
               SPACE COMPL. =O(1)

*/

struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
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

void flatten(struct TreeNode *root)
{
    struct TreeNode *current = root;
    struct TreeNode *prev = NULL;
    while (current)
    {
        if (current->left)
        {
            prev = current->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
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

    root->val = 1;
    root->left = second;
    root->right = third;

    second->val = 2;
    second->left = secondl;
    second->right = secondr;

    secondl->val = 3;
    secondl->left = NULL;
    secondl->right = NULL;

    secondr->val = 4;
    secondr->left = NULL;
    secondr->right = NULL;

    third->val = 5;
    third->left = NULL;
    third->right = thirdr;

    // thirdl->val = -1;
    // thirdl->left = NULL;
    // thirdl = NULL;

    thirdr->val = 6;
    thirdr->left = NULL;
    thirdr->right = NULL;

    // Both head1 and head2 traversal
    preorder(root);
    flatten(root);
    printf("\n");
    preorder(root);

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