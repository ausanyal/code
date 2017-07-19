
/*
https://careercup.com/question?id=5112453361827840
M->       N->       T->       D->       E
|          |         |        | 
C         X         Y          L
|         |
A         Z
-> right pointer 
| down pointer 
Output should be 
M->C->A->N->X->Z->T->Y->D-L>E 

Write this to flatten 
flatten(Node head) { 

} 

Node { 
    Node right; 
    Node down; 
    char a; 
}
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct node_ {
    struct node_ *right;
    struct node_ *down;
    char a;
}node_t;

node_t e = {.right = NULL,  .down = NULL,   .a = 'E'};
node_t l = {.right = NULL,  .down = NULL,   .a = 'L'};
node_t d = {.right = &e,    .down = &l,     .a = 'D'};
node_t y = {.right = NULL,  .down = NULL,   .a = 'Y'};
node_t t = {.right = &d,    .down = &y,     .a = 'T'};
node_t z = {.right = NULL,  .down = NULL,   .a = 'Z'};
node_t x = {.right = NULL,  .down = &z,     .a = 'X'};
node_t n = {.right = &t,    .down = &x,     .a = 'N'};
node_t a = {.right = NULL,  .down = NULL,   .a = 'A'};
node_t c = {.right = NULL,  .down = &a,     .a = 'C'};
node_t m = {.right = &n,    .down = &c,     .a = 'M'};


void flatten(node_t* head) {
    if (!head) return;     
    cout << head->a << " ";
    node_t *t = head;
    while(t->down) {
        t = t->down;
        cout << t->a << " ";
    }
    if (head->right) flatten(head->right);
}

int main()
{
    flatten(&m);
    cout << endl;
    
    return 0;
}
