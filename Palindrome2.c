#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
vGiven the head of a singly linked list, return true if it is a
palindrome
 or false otherwise.

1> Find Middle element
2> Reverse from next of middle
3> traverse from reverse and first

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

bool palindrome(struct ListNode *head)
{
    struct ListNode *second_Last = head;
    struct ListNode *q = head;
    struct ListNode *prev = NULL;
    struct ListNode *reverse_element = NULL;
    struct ListNode *reverse_next = NULL;

    // Middle element q->next
    while (second_Last->next != NULL && second_Last->next->next != NULL)
    {
        second_Last = second_Last->next->next;
        q = q->next;
    }

    // reverse from q->next store it in reverse element
    reverse_element = q->next;

    prev = q;
    while (reverse_element)
    {
        reverse_next = reverse_element->next;
        reverse_element->next = prev;
        prev = reverse_element;
        reverse_element = reverse_next;
    }

    // free(reverse_element);
    // free(reverse_next);
    // free(second_Last);

    while (head != q && prev != q)
    {
        if (head->val != prev->val)
        {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    if (q->val != prev->val)
    {
        return false;
    }

    return true;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fifth = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 1;
    third->next = NULL;

    fourth->val = 4;
    fourth->next = NULL;

    fifth->val = 1;
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