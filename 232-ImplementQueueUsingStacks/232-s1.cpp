#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
 public:
  stack<int> s1;
  stack<int> s2;
  //   MyQueue() {}

  void push(int x) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    s2.push(x);
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

  int pop() {
    int front = s1.top();
    s1.pop();
    return front;
  }

  int peek() { return s1.top(); }

  bool empty() { return s1.empty(); }
};

int main() {
  // declaration
  MyQueue* myQueue = new MyQueue();

  // processing
  myQueue->push(1);
  myQueue->push(2);
  int param_2 = myQueue->peek();
  int param_3 = myQueue->pop();
  bool param_4 = myQueue->empty();

  // output
  cout << "top: " << param_2 << endl;
  cout << "pop: " << param_3 << endl;
  cout << "The stack now is " << (param_4 ? "empty" : "not empty") << endl;

  return 0;
}