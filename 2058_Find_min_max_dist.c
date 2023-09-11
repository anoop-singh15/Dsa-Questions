#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define INT_MAX 2147483647 
/*
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

void listTraversal(struct ListNode *head)
{

    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int *node_between(struct ListNode *head, int *returnSize)
{
   struct ListNode *temp = head->next;
    struct ListNode *prev = head;

    int *ret = (int *)malloc(2 * sizeof(int));
    int f = INT_MAX;
    int l = 0;
    int md=INT_MAX;
    int c = 1;

    *returnSize = 2;
    while (temp->next)
    {
        if (temp->val > max(prev->val, temp->next->val) || temp->val < min(prev->val, temp->next->val))
        {
            if(l!=0)
            {
                md=min(md,c-l);
            }
           
                f=min(f,c);
                l=c;

            
        }
        c++;
        prev = temp;
        temp = temp->next;
    }
    if(md==INT_MAX)
    {
        ret[0]=-1;
        ret[1]=-1;
        return ret;

    }
    ret[0] = md;
    ret[1] = l-f;
    return ret;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    int *arr;
    int a;

    head->val = 1;
    head->next = second;

    second->val = 21;
    second->next = third;

    third->val = 19;
    third->next = NULL;

    listTraversal(head);
    printf("\n");

    arr = node_between(head, &a);
    for (int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }

    free(head);
    free(second);
    free(third);

    return 0;
}