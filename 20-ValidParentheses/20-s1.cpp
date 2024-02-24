#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    map<char, char> parentheses;
    map<char, char>::iterator it;
    vector<char> stack;

    parentheses['('] = ')';
    parentheses['['] = ']';
    parentheses['{'] = '}';

    for (char c : s) {
      if (parentheses.find(c) != parentheses.end()) {
        stack.push_back(c);
      } else {
        if (stack.empty() || c != parentheses[stack[stack.size() - 1]]) {
          return false;
        } else {
          stack.pop_back();
        }
      }
    }

    return stack.size() == 0;
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