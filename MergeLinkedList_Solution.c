#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
modified merge Sorted linked list
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

void merge(struct ListNode *head1, struct ListNode *head2)
{
    struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *result;
 
    struct ListNode *dummy=temp;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val<head2->val)
        {
            dummy->next=head1;
            head1=head1->next;
           
        }
        else
        {
            dummy->next=head2;
            head2=head2->next;
        }
         dummy=dummy->next;
    }
    if(head1!=NULL)
    {
        dummy->next=head1;
    }
    if(head2!=NULL)
    {
        dummy->next=head2;
    }
    result=temp->next;
    free(temp);
    printf("\n");
    traversal(result);
}

int main()
{

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *q2 = NULL;

    head->val = 1;
    head->next = second;

    second->val = 3;
    second->next = third;

    third->val = 4;
    third->next = NULL;

    head2->val = 1;
    head2->next = second2;

    second2->val = 2;
    second2->next = third2;

    third2->val = 4;
    third2->next = NULL;

    traversal(head);
    printf("\n");

    traversal(head2);
    merge(head, head2);

    printf("\n");
    // traversal(q2);

    free(head);
    free(second);
    free(third);

    free(head2);
    free(second2);
    free(third2);
    free(q2);

    return 0;
}