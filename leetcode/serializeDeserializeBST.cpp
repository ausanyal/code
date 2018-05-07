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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      cout << "Serializing \n";
      string res;
      if (!root) return res;
      queue<TreeNode*> myq;
      myq.push(root); 
      while(!myq.empty()) {
        TreeNode* node = myq.front(); myq.pop();
        int sz = 3 * sizeof(int);
        char v[sz];
        memset(v, 0, sizeof(v));
        memcpy(v, &node->val, sizeof(int));
        int ll = 1, rr = 2;
        if (node->left) {
          memcpy(v + sizeof(int), &ll, sizeof(int));
          myq.push(node->left);
        }
        if (node->right) {
          memcpy(v + 2*sizeof(int), &rr, sizeof(int));
          myq.push(node->right);
        }

        ostringstream buffer;
        for (char c = 0; c < sz; ++c) {
          buffer << v[c];
        }
        res += buffer.str();
      }
      return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      cout << "Deserializing \n";
      if (!data.size()) return nullptr;
      cout << "Size: " << data.size() << "\n";
      const char *str_c = data.c_str(); 
      int len = data.size();
      int consumed = 0;
      int sz = 3 * sizeof(int);

      auto build_node = [&str_c, &consumed, &sz] (TreeNode **node) {
        int val;
        const char *temp = str_c + consumed;
        memcpy(&val, temp, sizeof(int));
        *node = new TreeNode(val);

        int l = *(int *)(str_c + consumed + sizeof(int));
        int r = *(int *)(str_c + consumed + 2*sizeof(int));
        consumed += sz;
        return make_pair(l, r);
      };

      queue<TreeNode**> myq;
      TreeNode *root = nullptr;
      myq.push(&root);

      while (!myq.empty()) {
        if (consumed >= len) break;
        TreeNode** node = myq.front(); myq.pop();

        pair<int, int> ret = build_node(node);
        if (ret.first) {
          myq.push(&(*node)->left); 
        }
        if (ret.second) {
          myq.push(&(*node)->right); 
        }
      }
      PrintTreeBFS(root);
      return root;
    }
};

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

int main() {
  // Your Codec object will be instantiated and called as such:
  // Codec codec;
  // codec.deserialize(codec.serialize(root));

  Codec codec;
  srand((unsigned int)time(0));
  TreeNode *root = nullptr;
  BuildRandomTree(&root, 1);
  cout << "=============== Printing tree \n";
  PrintTreeBFS(root);
  string s = codec.serialize(root);
  codec.deserialize(s);
  //codec.deserialize(codec.serialize(root));
  return 0;
}
