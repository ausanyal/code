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
#include <map>
#include <queue>
#include <vector>
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
    vector<string> paths;
    void addPaths(TreeNode* root, vector<string>& paths, string& thisPath) {
       if (!root->left && !root->right) {
           thisPath.append(to_string(root->val));
           paths.emplace_back(thisPath);
           //cout << "Added: " << thisPath << endl;
           return;
       }
       thisPath.append(to_string(root->val));
       string subPath1 = thisPath;
       string subPath2 = thisPath;
       if (root->left) {
           //cout << "root: " << root->val <<  " going left. thisPath so far: " << thisPath << "\n";
           addPaths(root->left, paths, subPath1);
       } 
       if (root->right) { 
           //cout << "root: " << root->val <<  " going right. thisPath so far: " << thisPath << "\n";
           addPaths(root->right, paths, subPath2);
       }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string thisPath;
        addPaths(root, paths, thisPath);
        return paths;
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
    queue<TreeNode *> q;
    if (!root) return;
    q.push(root);
    while(!q.empty()) {
        TreeNode *t = q.front();
        q.pop();
        cout << t->val << " ";
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
}

void dfs(TreeNode *root) {
    if (!root) return;
    dfs(root->left);
    cout << root->val << " ";
    dfs(root->right);
}

int main()
{
    Solution s;
    TreeNode *root = NULL;
#if 0
    for (int i = 0; i < 10; i++) {
        if (i%2==0) {
            int j = 5-i/2;
            cout << "j " << j << endl;
            insertIntoTree(&root, j);
        } else {
            int k = 5+i;
            cout << "k " << k << endl;
            insertIntoTree(&root, k);
        }
    }
#endif
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

    dfs(root);
    cout << "\n";
    bfs(root);
    cout << endl;
    //cout << s.binaryTreePaths(root) << endl;
    vector<string> paths = s.binaryTreePaths(root);
    for (auto s:paths) cout << s << " ";
    cout << "\n";

    return 0;
}
