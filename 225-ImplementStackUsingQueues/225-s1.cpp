#include <iostream>
#include <queue>

using namespace std;

class MyStack {
 public:
  queue<int> q;
  // MyStack() {

  // }

  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++) {
      int oldest = q.front();
      q.pop();
      q.push(oldest);
    }
  }

  int pop() {
    int top = q.front();
    q.pop();
    return top;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};

int main() {
  // declaration
  MyStack* myStack = new MyStack();

  // processing
  myStack->push(1);
  myStack->push(2);
  int param_2 = myStack->top();
  int param_3 = myStack->pop();
  bool param_4 = myStack->empty();

  // output
  cout << "top: " << param_2 << endl;
  cout << "pop: " << param_3 << endl;
  cout << "The stack now is " << (param_4 ? "empty" : "not empty") << endl;

  return 0;
}