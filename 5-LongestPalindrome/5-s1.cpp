#include <iostream>  // preprocessor directive
#include <string>

using namespace std;  // using directive

// leetcode time limit exceeded...
class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (len < 2) {
      return s;
    }

    string res = s.substr(0, 1);
    int maxLen = 1;

    for (int i = 0; i < len; i++) {
      for (int j = i + maxLen + 1; j <= len; j++) {
        string str = s.substr(i, j - i);
        int substrLen = j - i;
        if (substrLen > maxLen && isPalindrome(str)) {
          res = str;
          maxLen = substrLen;
        }
      }
    }

    return res;
  }

  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};

int main() {
  // declaration
  Solution s;
  string str, res;

  // input
  cout << "\nEnter a string: ";
  cin >> str;

  // processing
  res = s.longestPalindrome(str);

  // output
  cout << "\n\nResult:\n";
  cout << "The longest palindromic substring is \"" << res << "\"\n\n";

  return 0;
}