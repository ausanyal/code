#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <time.h>

using namespace std;
using namespace chrono;

//template <typename T>
struct node {
    struct node *l, *r;
    int val;
    node (int v) : val(v), l(NULL), r(NULL) {}
};

int numNodes = 14;
mutex mtx;

void buildTree(struct node **root, int min, int max) {
    thread t1, t2;
    {
        lock_guard<mutex> lk(mtx);
        cout << "NumNodes: " << numNodes << "\n";
        if (!numNodes) {
            cout << "Done \n";
            return;
        }
        int mid = (min + max) / 2;
        int val = mid;
        //cout << "val " << val << " min " << min
        //<< " mid " << mid << " max " << max << "\n";
        if(!(*root)) {
            *root = new node(mid);
            --numNodes;
        } else cout << "Error \n";
        
        t1 = thread(buildTree, &(*root)->r, val+1, max);
        t2 = thread(buildTree, &(*root)->l, min, val-1);
        
    }
    t1.join();
    t2.join();
}

bool verifyVal(int val, int min, int max) {
    if (val >= min && val <= max) return true;
    else return false;
}

void walkTreeBFS(struct node *root, int min, int max) {
    if (!root) return;
    
    if (root->val < min || root->val > max) {
        cout << root->val << " min " << min << " max " << max << "\n";
        return;
    }
    
    queue<struct node *> myq;
    myq.push(root);
    cout << "Pushing " << root->val << "\n";
    while(!myq.empty()) {
        struct node *t = myq.front();
        myq.pop();
        cout << t->val << " ";
        if (t && t->l && verifyVal(t->l->val, min, max)) myq.push(t->l);
        if (t && t->r && verifyVal(t->r->val, min, max)) myq.push(t->r);
    }
    cout << "\n";
}

void walkTreeDFS(struct node *root) {
    if (!root) return;
    cout << root->val << " ";
    if (root->l) walkTreeDFS(root->l);
    if (root->r) walkTreeDFS(root->r);
}

int main()
{
    srand(time(NULL));
    
    struct node *root = NULL;
    buildTree(&root, 0, 100);
    walkTreeBFS(root, 37, 43);
    walkTreeDFS(root);
    cout << "\n";
    return 0;
}
