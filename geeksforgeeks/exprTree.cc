// C++ program for expression tree
#include <iostream>
#include <stack>

using namespace std;
 
// An expression tree node
struct et
{
    char value;
    et* left, *right;
};
 
// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

int myEval(char c, int operand1, int operand2) {
  if (c == '+') {
    return (operand1 + operand2);
  } else if (c == '-') {
    return (operand1 - operand2);
  } else if (c == '*') {
    return (operand1 * operand2);
  } else if (c == '/') {
    return (operand1 / operand2);
  } else if (c == '^') {
    return (operand1 ^ operand2);
  } else {
    return 0;
  }
}

// Utility function to do inorder traversal
void inorder(et *t)
{
    if(t) {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}
 
int evalExprTree(et *t) {
  if (!t) return 0;

  if (isOperator(t->value)) {
    int val1 = evalExprTree(t->left);
    int val2 = evalExprTree(t->right);
    int n = myEval(t->value, val1, val2);
    cout << val1 << " " << t->value << " " << val2 << " = " << n << "\n";
    return n;
  } else {
    cout << "Operand: " << t->value << "\n";
    return (t->value - '0');
  }
}

// A utility function to create a new node
et* newNode(int v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

/*
int atoi(char s[]) {
  int num = 0;
  for (int i = 0; i < strlen(s); ++i) {
    num *= 10;
    num += s[i];
  }
  return num;
}
*/

et *constructTree(char postfix[]) {
  stack<et *> st;
  for (int i = 0; i < strlen(postfix); ++i) {
    char c = postfix[i];
    if (!isOperator(c)) {
      et *op = newNode(c);
      st.push(op);
    } else {
      et *operator1 = st.top(); st.pop();
      et *operator2 = st.top(); st.pop();
      et *n = newNode(c);
      n->left = operator2;
      n->right = operator1;
      st.push(n);
    }
  }
  et *t = st.top(); st.pop();
  return t;
}


// Returns root of constructed tree for given
// postfix expression
et* constructTree2(char postfix[])
{
    stack<et *> st;
    et *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);
 
            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
 
            //  make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}
 
// Driver program to test above
int main()
{
    char postfix[] = "32+56*7*-";
    et* r = constructTree(postfix);
    printf("infix expression is \n");
    inorder(r);
    cout << "\n";
    evalExprTree(r);
    cout << "\n";
    return 0;
}
