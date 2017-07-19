//https://leetcode.com/problems/rotate-list/#/description
/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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

  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;
    ListNode *newH, *tail;
    int len = 1;
    tail = head;
    while(tail->next) {
      tail = tail->next;
      len++;
    }

    tail->next = head;

    if (k %= len) {
      for (int i = 0; i < len-k; i++) {
        tail = tail->next;
      }
    }
    newH = tail->next;
    tail->next = NULL;
    return newH;
  }

    ListNode* rotateRight2(ListNode* head, int k) {
      ListNode *t1 = head, *t2 = head, *t0 = NULL;
      int n = k;
      if (!head) return NULL;
      if (n == 0) return head;
      n--;
      int size = 0;
      while(n) {
        size++;
        if (t2->next) {
          t2 = t2->next;
        } else {
          break;
        }
        n--;
        if (!n) size = 0;
      }
      cout << "A " << t2->val << " " << t1->val << " size " << size << "\n";
      if (size) {
       int moves = k % size;
       cout << "Move set to " << moves << "\n";
       if (!moves) return head;
       t2 = head;
       moves--;
       while(moves) {
         if (t2->next) t2 = t2->next;
         moves--;
       }
       cout << "A2 " << t2->val << " " << t1->val << "\n";
      }
      t0 = t1;
       while(t2->next) {
        t2 = t2->next;
        t0 = t1;
        t1 = t1->next;
      }
      cout << "B " << t2->val << " " << t1->val << " " << t0->val <<  "\n";
      // Still at original head
      if (t0 == t1 && !n) {
        cout << "Special case \n";
        return head;
      }
      t2->next = head;
      t0->next = NULL;
      cout << t1->val << endl;
      if (t0 == t1) return t2;
      return t1;
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
    insertIntoList({1, 2, 3}, &head);
    printList(head);
    ListNode *t = s.rotateRight(head, 6);
    if (!t) cout << "Error \n";
    cout << "List: \n";
    printList(t);
    return 0;
}
