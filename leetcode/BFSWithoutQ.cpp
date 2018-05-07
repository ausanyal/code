/*
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * Serialization is the process of converting a data structure or object into 
 * a sequence of bits so that it can be stored in a file or memory buffer, or 
 * transmitted across a network connection link to be reconstructed later in 
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. 
 * There is no restriction on how your serialization/deserialization algorithm 
 * should work. You just need to ensure that a binary search tree can be 
 * serialized to a string and this string can be deserialized to the original 
 * tree structure.
 *
 * The encoded string should be as compact as possible.
 *
 * Note: Do not use class member/global/static variables to store states. 
 * Your serialize and deserialize algorithms should be stateless.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <sstream>
#include <utility>

using namespace std;

#define TREE_DEPTH 6

int tree_sz = 0;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {
    tree_sz++;
  }
};

void PrintTreeBFS(TreeNode *root) {
  queue<TreeNode*> myq;
  myq.push(root);
  int count = 0, expected = 1;
  while(!myq.empty()) {
    ++count;
    TreeNode* node = myq.front(); myq.pop();
    cout << node->val << " "; 
    if (count == expected ) {
      cout << " << \n";
      expected *= 2;
      count = 0;
    }
    if (node->left) myq.push(node->left);
    if (node->right) myq.push(node->right);
  }
}

void BuildRandomTree(TreeNode **root, int depth) {
  if (depth == TREE_DEPTH) return;

  int val = 0;
  if (*root == nullptr) {
    // int val = rand()%1000;
    val = rand()%1000; 
    *root = new TreeNode(val);
  } 

  depth++;
  BuildRandomTree(&(*root)->left, depth);
  BuildRandomTree(&(*root)->right, depth);
}

bool BFSInternal(TreeNode* root, int depth, int curr_ht) {
  if (!root) return 0;
  if (curr_ht == depth) {
    cout << root->val << " ";
    return 1;
  } 

  bool l = BFSInternal(root->left, depth, curr_ht+1); 
  bool r = BFSInternal(root->right, depth, curr_ht+1);
  return (l | r);
}

void BFS(TreeNode* root) {
 int depth = 0;
 if (root == NULL) return;

  while(BFSInternal(root, depth, 0)) {
    cout << "\n";
    ++depth;
  }
}

int main() {
  // Your Codec object will be instantiated and called as such:
  // Codec codec;
  // codec.deserialize(codec.serialize(root));

  srand((unsigned int)time(0));
  TreeNode *root = nullptr;
  BuildRandomTree(&root, 1);
  cout << "=============== Printing tree \n";
  PrintTreeBFS(root);
  BFS(root);
  //codec.deserialize(codec.serialize(root));
  return 0;
}
