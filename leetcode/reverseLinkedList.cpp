//https://leetcode.com/problems/reverse-linked-list-ii/
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/
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
 
class Solution {
public:
    ListNode *findNodeWithLoc(ListNode* head, ListNode **prev, int m) {
        int t = 0;
        ListNode *temp = head;
        if (m == 0) {
            *prev = NULL;
            return head;
        }
        while(temp != NULL && t < m-1) {
            *prev = temp;
            temp = temp->next;
            t++;
        }
        return temp;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int t=0;
        int d = n-m;
        ListNode* temp, *p = NULL;

        temp = findNodeWithLoc(head, &p, m);
        cout << "temp: " << temp->val << " p: " << p << endl;
        if (!temp) return NULL;
        ListNode *curr = temp->next, *prev = temp, *next;
        cout << "prev: " << prev->val << " curr: " << curr->val << endl;
        while((curr != NULL) && (t < d)) { 
            if (prev == head) prev->next = NULL;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            t++;
            cout << "t: " << t << " prev: " << prev->val << " curr: " << curr->val << endl;
            ListNode *h = prev;
            while(h != temp) {
                cout << h->val << " ";
                h = h->next;
            }
            cout << endl;
        }
        cout << "... temp: " << temp->val  <<  " curr: " << curr->val << 
            " prev: " << prev->val << " p: " << p << endl;
        temp->next = curr; 
        if (p) p->next = prev;
        else head = prev;
        return head;    
    }

    ListNode *reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *prev, *curr, *next;
        prev = head;
        curr = prev->next;
        while(curr != NULL) {
            if (prev == head) prev->next = NULL;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main()
{
    Solution s;
    ListNode *head1 = NULL, *t = NULL;
    for (int i = 0; i < 10; i++) {
        ListNode *x = new ListNode(i+1);
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
    ListNode* h = s.reverseBetween(head1, 2, 5);
    while(h) {
        cout << h->val << " ";
        h = h->next;
    }

    cout << endl;
    return 0;
}
