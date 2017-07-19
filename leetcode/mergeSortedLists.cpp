//https://leetcode.com/problems/merge-two-sorted-lists/
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 typedef ListNode node;
class Solution {
    node* mergeLists(node *l1, node *l2) {
        return NULL;
    }
public:
    node *t = NULL;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        if (l1 &&!l2) return l1;
        if (!l1 && l2) return l2;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    ListNode *head1 = NULL, *head2 = NULL, *t = NULL;
    for (int i = 0; i < 10; i++) {
        ListNode *x = new ListNode(i*2);
        if (!head1) head1 = x;
        if (t) t->next = x;
        t = x;
    }
    t = head1;
    while(t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    for (int i = 0; i < 7; i++) {
        ListNode *x = new ListNode(i*2+1);
        if (!head2) head2 = x;
        if (t) t->next = x;
        t = x;
    }
    t = head2;
    while(t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    Solution s;
    t = s.mergeTwoLists(head1, head2);
    while(t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
