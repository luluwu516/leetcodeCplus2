#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    if (n == 1) {
      return true;
    }
    if (n % 2 != 0) {
      return false;
    }

    return isPowerOfTwo(n / 2);
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
  res = s.isPowerOfTwo(num);

  // output
  cout << "\n\nResult: " << endl;
  cout << "Number is " << (res ? "" : "not ") << "a power of two" << endl
       << endl;

  return 0;
}