//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

      After removing the second node from the end, the linked list becomes 1->2->3->5.
      Note:
      Given n will always be valid.
      Try to do this in one pass.
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (!head) return NULL;
            ListNode *fast = head, *slow = head;
            int t = 0;
            while(t < n) {
                if (!fast) return NULL;
                t++;
                fast = fast->next;
            }
            while(fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            ListNode *temp = slow->next;
            slow->next = fast; 
            delete temp;
            cout << "fast: " << fast->val << " slow: " << slow->val << endl;
            return head;
        }
};

int main() {
    Solution s;
    ListNode *l11 = new ListNode(1);
    ListNode *l12 = new ListNode(2);
    ListNode *l13 = new ListNode(3);
    ListNode *l21 = new ListNode(4);
    ListNode *l22 = new ListNode(5);
    ListNode *l23 = new ListNode(6);

    l11->next = l12;
    l12->next = l13;
    l13->next = l21;
    l21->next = l22;
    l22->next = l23;

    ListNode *ret = s.removeNthFromEnd(l11, 2);
    while(ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << "\n";

    return 0;
}
