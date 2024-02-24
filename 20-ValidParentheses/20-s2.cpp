#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        if (st.empty()) {
          return false;
        } else if (c == ')' && st.top() == '(') {
          st.pop();
        } else if (c == ']' && st.top() == '[') {
          st.pop();
        } else if (c == '}' && st.top() == '{') {
          st.pop();
        } else {
          return false;
        }
      }
    }

    return st.size() == 0;
  }
};

int main() {
  // declaration
  Solution s;
  string strs;

  // input
  cout << ("Enter parentheses, such as '(', ')', '{', '}', '[' or ']': ");
  cin >> strs;

  // Processing and Output
  if (s.isValid(strs)) {
    cout << ("\nThe parentheses is vaild.\n");
  } else {
    cout << ("\nThe parentheses is invaild.\n");
  }

  return 0;
}