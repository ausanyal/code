// https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/


/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x)
      : val(x),
        next(NULL) {
  }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *t1 = head, *t2 = head, *t0 = NULL;
      n--;
      while(n) {
        if (t2->next) {
          t2 = t2->next;
        } else break;
        n--;
      }
      if (n) return NULL;
      cout << t2->val << " " << t1->val << "\n";
      t0 = t1;
       while(t2->next) {
        t2 = t2->next;
        t0 = t1;
        t1 = t1->next;
      }
       cout << t2->val << " " << t1->val << " " <<  "\n";
      if (t0 == t1) {
        cout << "..\n";
        return t0->next;
        t1->next = NULL;
        delete(t1);
      }
      t0->next = t1->next;
      t1->next = NULL;
      delete(t1);
      cout << t1->val << endl;
      return head;
    }
};

void insertIntoList(vector<int> arr, ListNode **head) {
  for (int i : arr) {
    cout << i << endl;
    ListNode *t = new ListNode(i);
    if (*head == NULL) {
      *head = t;
    } else {
      ListNode *x = *head;
      while(x->next) x = x->next;
      x->next = t;
    }
  }
}

void printList(ListNode *h) {
  ListNode *t = h;
  while(t != NULL) {
    cout << t->val << " ";
    t = t->next;
  }
  cout << "\n";
}

int main() {
    Solution s;
    ListNode *head = NULL;
    insertIntoList({1}, &head);
    printList(head);
    ListNode *t = s.removeNthFromEnd(head, 1);
    if (!t) cout << "Error \n";
    cout << "List: \n";
    printList(t);
    return 0;
}
