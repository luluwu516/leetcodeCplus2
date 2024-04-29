#include <ctype.h>

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    string letters = "";

    for (auto c : s) {
      if (isalnum(c)) {
        letters.push_back(tolower(c));
      }
    }

    int left = 0, right = letters.length() - 1;
    while (left < right) {
      if (letters[left] != letters[right]) {
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