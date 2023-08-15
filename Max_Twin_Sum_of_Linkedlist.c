#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/

/*
1> Find Middle element
2> reverse element after middle
3> compare sum from 2 linked list
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

int sum(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev = NULL;
    struct ListNode *slow_next = NULL;
    struct ListNode *current = NULL;
    int max = 0;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // traversal(slow);
    // reverse from next of slow
    current = slow->next;
    prev = slow;
    while (current)
    {
        slow_next = current->next;
        current->next = prev;
        prev = current;
        current = slow_next;
    }

    // Logic for max
    while (head != slow && prev != slow)
    {
        if (max < (head->val + prev->val))
        {
            max = (head->val + prev->val);
        }
        head = head->next;
        prev = prev->next;
    }
    if(max<(head->val+prev->val))
    {
        max=(head->val+prev->val);
    }
    return max;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = NULL;

    head->val = 1;
    head->next = second;

    second->val = 100000;
    second->next = NULL;

    third->val = 2;
    third->next = fourth;

    fourth->val = 1;
    fourth->next = fifth;

    fifth->val = 0;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    // q = merge(head);
    printf("%d\n", sum(head));
    // traversal(q);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(q);

    return 0;
}