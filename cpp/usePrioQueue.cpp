#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct node_ {
  int num;
  struct node_ *left;
  struct node_ *right;
 public:
  node_(int val)
      : num (val),
        left (nullptr),
        right (nullptr) {}
} node;

class myHeap {
 private:
  int heapSz;
  int currSize;
  vector<int> arr;
 public:
  myHeap(int size = 10)
      : heapSz(size),
        currSize(0),
        root(NULL) {
    arr.reserve(heapSz);
  }
  void push(int num);
  void maxHeapify(node *root, int num);
  int pop();
};

void
myHeap::maxHeapifyTrickleUp(int pos) {
  int parent = (pos-1)/2;
  if (arr[pos-1] > arr[parent]) {
    iter_swap(arr.begin() + (pos-1), arr.begin() + parent);
  }

}

void
myHeap::push(int num) {
  if (root == NULL) {
    arr.push_back(num);
    return;
  }
  arr.push_back(num)
  maxHeapifyTrickleUp(arr.size());
}


struct Compare {
 public:
  bool operator()(const int& a, const int& b) {
    return a < b;
  }
};

int main()
{
  priority_queue<int, vector<int>, Compare> pq;
  pq.push(10);
  pq.push(20);
  while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  myHeap mHeap;
  return 0;
}
