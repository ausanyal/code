//https://leetcode.com/problems/add-two-numbers/
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        ListNode *res = NULL, *curr_node = NULL;
        int r = 0;
        while(l1 != NULL || l2 != NULL) {
            if (!res) {
                res = new ListNode(0);
                curr_node = res;
            } else {
                curr_node->next = new ListNode(0);
                curr_node = curr_node->next;
            }
            int t = 0;
            if (r) {
                t += r;
                r = 0;
            }
            if (l1) { 
                t += l1->val; 
                l1 = l1->next; 
            }
            if (l2) { 
                t += l2->val; 
                l2 = l2->next; 
            }
            //cout << "t: " << t << endl;
            if (t >= 10) {
                curr_node->val = t % 10;
                r = t / 10;
            } else {
                curr_node->val = t;
            }
        }
        if (r) {
            curr_node->next = new ListNode(0);
            curr_node = curr_node->next;
            curr_node->val = r;
        }
        return res;   
    }
};

int main() {
    Solution s;
    ListNode *l11 = new ListNode(9);
    ListNode *l12 = new ListNode(8);
    ListNode *l13 = new ListNode(7);
    l11->next = l12;
    l12->next = l13;

    ListNode *l21 = new ListNode(7);
    ListNode *l22 = new ListNode(8);
    ListNode *l23 = new ListNode(6);
    l21->next = l22;
    l22->next = l23;

    ListNode *ret = s.addTwoNumbers(l11, l21);
    while(ret != NULL) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << "\n";
    return 0;
}
