//https://leetcode.com/problems/binary-tree-paths/
/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
     bool inorderTraversalRecursive(TreeNode* root, vector<int>& a) {
       if (!root) return false;
       inorderTraversalRecursive(root->left, a);
       a.push_back(root->val);
       inorderTraversalRecursive(root->right, a);
       return true;
     }

     vector<int> inorderTraversal(TreeNode* root) {
       vector<int> a;
       inorderTraversalRecursive(root, a);
       return a;
     }
 };
 
void insertIntoTree(TreeNode **root, int i) {
    if (!(*root)) {
        *root = new TreeNode(i);
        return;
    }
    if (i > (*root)->val) insertIntoTree(&(*root)->right, i);
    else insertIntoTree(&(*root)->left, i);
}

void bfs(TreeNode *root) {
  queue<TreeNode*> myq;
  if (!root) return;

  myq.push(root);
  queue<TreeNode *> q;
  if (!root) return;
  q.push(root);

  while(!myq.empty()) {
    TreeNode* t = myq.front();
    cout << t->val << " ";
    myq.pop();
    if (t->left) myq.push(t->left);
    if (t->right) myq.push(t->right);
  }
}

int main()
{
    Solution s;
    TreeNode *root = NULL;
    insertIntoTree(&root, 5);
    insertIntoTree(&root, 3);
    insertIntoTree(&root, 2);
    insertIntoTree(&root, 4);
    insertIntoTree(&root, 1);
    insertIntoTree(&root, 10);
    insertIntoTree(&root, 8);
    insertIntoTree(&root, 9);
    insertIntoTree(&root, 6);
    insertIntoTree(&root, 7);
    insertIntoTree(&root, 14);
    insertIntoTree(&root, 15);
    insertIntoTree(&root, 12);

    vector<int> v = s.inorderTraversal(root);
    for (int i : v) cout << i << " . ";
    cout << "\n";
    bfs(root);

    return 0;
}
