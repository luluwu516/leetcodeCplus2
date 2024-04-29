#include <ctype.h>

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
      while (!isalnum(s[left]) && left < right) {
        left++;
      }
      while (!isalnum(s[right]) && left < right) {
        right--;
      }

      if (tolower(s[left]) != tolower(s[right])) {
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
  Solution s = Solution();
  string str;
  bool res;

  // input
  cout << "\nEnter a string: ";
  cin >> str;

  res = s.isPalindrome(str);

  // output
  cout << "\nResult:\n";
  cout << "The string is " << (res ? "palindrome." : "not palindrome.")
       << "\n\n";

  return 0;
}