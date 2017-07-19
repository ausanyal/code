//https://leetcode.com/problems/odd-even-linked-list/
/*
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
 */

#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 21

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;
void build_list(Node **head);
void print_list(Node *head);

void alternate_list(struct ListNode **head) {
    Node *a, *b, *p = NULL, *t;
    
    if (!(*head) || !(*head)->next) {
        return;
    } 

    a = *head;
    b = (*head)->next;
    t = b->next;

    while(a && b) {
        b->next = a;
        a->next = t;
        if (a == *head) *head = b;
        printf("a and b swapped\n");
        print_list(*head);
        if (p) {
            p->next = b;
        }
        p = a;
        a = t;
        if (a) b = a->next;
        if (a && b) t = b->next;
    }

    return;
}

int main()
{
    Node *head, *n;
    build_list(&head); 
    alternate_list(&head);
    n = head;
    print_list(head);
    return 0;
}

void build_list(Node **head)
{

    Node *n, *prev;

    for (int i = 0; i < LIST_SIZE; i++) {
        n = (Node *)malloc(sizeof(Node));
        n->val = i+1;
        if (i == 0) *head = n;
        else prev->next = n;
        prev = n;
    }
    n->next = NULL;
    
    print_list(*head);
}

void print_list(Node *head)
{

    Node *n;
    n = head;
    while(n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");

}
