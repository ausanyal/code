/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <stack>

 using namespace std;

#define DEFAULT_STARTING_STACK 2

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 template <class T>
 class myStack {
     T *arr;
     int stackSize, topIndex;
public:
    myStack();
    void push(T item);
    T& top();
    bool pop();
    bool empty();
    void printStack();
 };

template <class T>
void myStack<T>::printStack() {
    for (int i = 0; i < topIndex; i++) {
        cout << "printStack:" <<  arr[i] << endl;
    }
}

template <class T>
myStack<T>::myStack() {
    stackSize = DEFAULT_STARTING_STACK;
    topIndex = 0;
    arr = (T *)malloc(stackSize*sizeof(T));
    memset(arr, 0, stackSize*sizeof(T));
}

template <class T>
bool myStack<T>::empty() {
    return ((topIndex-1) < 0);
}

template <class T>
T& myStack<T>::top() {
    return arr[topIndex-1];
}

template <class T>
void myStack<T>::push(T value) {
    if (topIndex == (stackSize-1)) {
        cout << "Reallocating arr from: " << stackSize << " to: " << stackSize*2 << endl;
        stackSize = 2 * stackSize;
        arr = (T *)realloc(arr, sizeof(stackSize));
    } 
    arr[topIndex++] = value;
}

template <class T>
bool myStack<T>::pop() {
    if (topIndex >= 0) {
        memset(&arr[topIndex], 0, sizeof(T));
        topIndex--;
        return true;
    } else {
        return false;
    }
}

class Solution {
public:
    void printReversedList(ListNode* head) {
        myStack<ListNode *> mystack;       
        while(head != NULL) { 
            mystack.push(head);
            head = head->next;
        }
        while(!mystack.empty()) {
            cout << mystack.top()->val << endl;
            mystack.pop();
        }
    }
    void printReversedList2(ListNode* head) {
        if (head == NULL) return;
        printReversedList2(head->next);
        cout << head->val << " ";
    }
};

int main()
{
    Solution s;
    ListNode *t = NULL, *head = NULL;
    for (int i = 0; i < 5; i++) {
        ListNode *n = new ListNode(i+1);
        if (t != NULL) {
            t->next = n;
        } else head = n;
        t = n;
    }
    t = head;
    while(t != NULL) { 
        cout << " " << t->val;
        t = t->next;
    }
    cout << endl;
    s.printReversedList(head);
    s.printReversedList2(head);
    cout << "\n";
    return 0;
}
