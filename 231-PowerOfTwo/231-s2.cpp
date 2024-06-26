#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }

    for (int i = 0; i < 31; i++) {
      if (pow(2, i) == n) {
        return true;
      }
    }
    return false;
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