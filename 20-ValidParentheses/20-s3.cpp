#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.length() % 2 == 1) {
      return false;
    }

    vector<char> v;

    for (char c : s) {
      if (c == '(') {
        v.push_back(')');
      } else if (c == '[') {
        v.push_back(']');
      } else if (c == '{') {
        v.push_back('}');
      } else if (v.empty() || v.back() != c) {
        return false;
      } else {
        v.pop_back();
      }
    }

    return v.size() == 0;
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