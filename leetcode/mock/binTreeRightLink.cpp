#include <iostream>
#include <queue>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void printTree(TreeLinkNode *root) {
  cout << root->val << " ";
  if (root->next)
    cout << root->next->val;
  cout << endl;
  if (root->left)
    printTree(root->left);
  if (root->right)
    printTree(root->right);
}

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root)
      return;
    queue<TreeLinkNode *> myq;
    myq.push(root);
    TreeLinkNode *t;
    cout << "Pushed: " << root->val << endl;
    while ((t = myq.front()) != NULL) {
      myq.pop();
      vector<TreeLinkNode *> tv;
      tv.push_back(t);
      cout << "Popped: " << t->val << endl;
      while (myq.size()) {
        TreeLinkNode *u = myq.front();
        myq.pop();
        tv.push_back(u);
        cout << " Got u: " << u->val << " t: " << t->val << endl;
        t->next = u;
        t = u;
        printTree(root);
      }
      for (auto &x : tv) {
        cout << "Walking tv. x: " << x->val << endl;
        if (x->left)
          myq.push(x->left);
        if (x->right)
          myq.push(x->right);
      }
    }
  }
};

int main() {
  Solution s;

  TreeLinkNode *tl1 = new TreeLinkNode(1);
  TreeLinkNode *tl2 = new TreeLinkNode(2);
  TreeLinkNode *tl3 = new TreeLinkNode(3);
  TreeLinkNode *tl4 = new TreeLinkNode(4);
  TreeLinkNode *tl5 = new TreeLinkNode(5);
  TreeLinkNode *tl6 = new TreeLinkNode(6);
  TreeLinkNode *tl7 = new TreeLinkNode(7);

  tl1->left = tl2;
  tl1->right = tl3;

  tl2->left = tl4;
  tl2->right = tl5;

  tl3->left = tl6;
  tl3->right = tl7;

  cout << tl1->val << endl;
  TreeLinkNode *tl = new TreeLinkNode(0);
  s.connect(tl3);
  printTree(tl3);

  return 0;
}
