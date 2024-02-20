#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    else if (x < 10)
      return true;

    long temp = x;
    long reversed = 0;
    int dig;

    while (temp != 0) {
      dig = temp % 10;
      reversed = reversed * 10 + dig;
      temp /= 10;
    }

    return x == reversed;
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
