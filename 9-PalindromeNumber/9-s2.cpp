#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    else if (x < 10)
      return true;

    string numString = to_string(x);
    string::iterator left = numString.begin();
    // string::iterator.end() points to the position after the last character
    string::iterator right = numString.end() - 1;

    while (left < right) {
      if (*left != *right) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};

int main() {
  // declaraction
  Solution s;
  int num;

  // input
  cout << "Enter an integer: ";
  cin >> num;

  // processing and output
  cout << "\nResult: ";
  if (s.isPalindrome(num)) {
    cout << num << " is a Palindrome Number.\n";
  } else {
    cout << num << " is not a Palindrome Number.\n";
  }

  return 0;
}
