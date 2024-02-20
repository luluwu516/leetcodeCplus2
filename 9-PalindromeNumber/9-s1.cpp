#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    } else if (x < 10) {
      return true;
    }

    return testPalindrome(to_string(x), 0, std::to_string(x).size() - 1);
  }

  bool testPalindrome(string palindrome, size_t left, size_t right) {
    if (left >= right) {
      return true;
    }
    if (palindrome[left] != palindrome[right]) {
      return false;
    }

    return testPalindrome(palindrome, left + 1, right - 1);
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
