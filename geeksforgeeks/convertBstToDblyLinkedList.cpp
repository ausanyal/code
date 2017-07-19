// http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list
/*
Convert a given Binary Tree to Doubly Linked List | Set 1
Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and
right pointers in nodes are to be used as previous and next pointers
respectively in converted DLL. The order of nodes in DLL must be same as Inorder
of the given Binary Tree. The first node of Inorder traversal (left most node in
BT) must be head node of the DLL.

TreeToList
                 BST:
                =====
                  10
            12          15
          25  30      36
                List:
               ======
25 <-> 12 <-> 10 <-> 36 <-> 15

I came across this interview during one of my interviews. A similar problem is
discussed in this post. The problem here is simpler as we don’t need to create
circular DLL, but a simple DLL. The idea behind its solution is quite simple and
straight.

1. If left subtree exists, process the left subtree
…..1.a) Recursively convert the left subtree to DLL.
…..1.b) Then find inorder predecessor of root in left subtree (inorder
predecessor is rightmost node in left subtree).
…..1.c) Make inorder predecessor as previous of root and root as next of inorder
predecessor.
2. If right subtree exists, process the right subtree (Below 3 steps are similar
to left subtree).
…..2.a) Recursively convert the right subtree to DLL.
…..2.b) Then find inorder successor of root in right subtree (inorder successor
is leftmost node in right subtree).
…..2.c) Make inorder successor as next of root and root as previous of inorder
successor.
3. Find the leftmost node and return it (the leftmost node is always head of
converted DLL).

Below is the source code for above algorithm.
*/
#include <iostream>

using namespace std;

/* A binary tree node has data, and left and right pointers */
struct node {
  int data;
  node *left;
  node *right;
  node(int x) : left(NULL), right(NULL), data(x){};
};

void printList(node *head) {
  node *temp = head;
  cout << "List: ";
  while (temp) {
    cout << temp->data << " ";
    temp = temp->right;
  }
  cout << endl;
}

node *inorderTraversal2(node *root, int which) {

  node *l = NULL, *r = NULL;
  if (root->left) {
    l = inorderTraversal2(root->left, 0);
  }
  node *temp = new node(root->data);
  cout << root->data << endl;
  temp->left = l;
  if (l) {
    l->right = temp;
  }
  if (root->right) {
    r = inorderTraversal2(root->right, 1);
  }
  temp->right = r;
  if (r) {
    r->left = temp;
  }
  if ((which == 0) && temp->right) {
    return temp->right;
  } else if ((which == 1) && temp->left) {
    return temp->left;
  } else
    return temp;
}

node *checkIfBst(node *root, bool &isBst) {
  node *l = NULL, *r = NULL;
  if (root->left) {
    l = checkIfBst(root->left, isBst);
    for (; l->right != NULL; l = l->right)
      ;
    if (l->data > root->data) {
      cout << "L Mismatch " << l->data << ">" << root->data << endl;
      isBst = false;
    }
  }

  if (root->right) {
    r = checkIfBst(root->right, isBst);
    for (; r->left != NULL; r = r->left)
      ;
    if (r->data < root->data) {
      cout << "R Mismatch " << r->data << "<" << root->data << endl;
      isBst = false;
    }
  }
  return root;
}

node *inorderTraversal(node *root) {
  node *l = NULL, *r = NULL;
  if (root->left) {
    l = inorderTraversal(root->left);
    for (; l->right != NULL; l = l->right)
      ;
    l->right = root;
    root->left = l;
  }

  if (root->right) {
    r = inorderTraversal(root->right);
    for (; r->left != NULL; r = r->left)
      ;
    r->left = root;
    root->right = r;
  }
  return root;
}

int main() {
  /* code */
  node *a1 = new node(10);
  node *a2 = new node(12);
  node *a3 = new node(15);
  node *a4 = new node(25);
  node *a5 = new node(30);
  node *a6 = new node(36);

  node *head = new node(0);

  a1->left = a2;
  a1->right = a3;
  a2->left = a4;
  a2->right = a5;
  a3->left = a6;
  node *t;
  t = inorderTraversal(a1);
  cout << " t " << t << endl;
  while (t->left) {
    t = t->left;
  }
  printList(t);

  bool isBst = true;
  cout << "is BST " << checkIfBst(a1, isBst) << endl;
  return 0;
}
