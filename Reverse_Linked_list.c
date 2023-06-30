#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.


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


// MY LOGIC 7ms Runtime
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *ptr = NULL;

    while (head != NULL)
    {
        struct ListNode *ptr2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        ptr2->val = head->val;
        ptr2->next = ptr;
        ptr = ptr2;
        head = head->next;
    }
    return ptr;
}

// ITERATIVE LOGIC
struct ListNode* reverseList2(struct ListNode *head)
{
    struct ListNode *current=head;
    struct ListNode *prevNode=NULL;
    struct ListNode *nextofcurrent=NULL;
    while(current!=NULL)
    {
        nextofcurrent=current->next;
        current->next=prevNode;
        prevNode=current;
        current=nextofcurrent;
    }
    return prevNode;

}



int main()
{

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *p;

    head->val = 1;
    head->next = second;

    second->val = 21;
    second->next = third;

    third->val = 19;
    third->next = NULL;

    listTraversal(head);
    printf("\n");

    // MY LOGIC
    // p = reverseList(head);

    // Iterative Logic
    p = reverseList2(head);

    listTraversal(p);

    free(head);
    free(second);
    free(third);

    return 0;
}