#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n <= 0) {
      return false;
    }

    while (n % 4 == 0) {
      n /= 4;
    }
    return n == 1;
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
  res = s.isPowerOfFour(num);

  // output
  cout << "\n\nResult: " << endl;
  cout << "Number is " << (res ? "" : "not ") << "a power of four." << endl
       << endl;

  return 0;
}