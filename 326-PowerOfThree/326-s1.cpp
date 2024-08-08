#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }
    if (n == 1) {
      return true;
    }
    if (n % 3 != 0) {
      return false;
    }
    return isPowerOfThree(n / 3);
  }
};

int main() {
  // declaration
  int num, res;
  Solution s;

  // input
  cout << "\nEnter a number: ";
  cin >> num;

  // processing
  res = s.isPowerOfThree(num);

  // output
  cout << "\n\nResult: " << endl;
  cout << "Number is " << (res ? "" : "not ") << "a power of three." << endl
       << endl;

  return 0;
}