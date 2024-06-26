#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    int rem;

    while (n != 1) {
      rem = n % 2;
      if (rem == 1) {
        return false;
      }
      n /= 2;
    }
    return true;
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