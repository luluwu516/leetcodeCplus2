#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }
    int rem;

    while (n != 1) {
      rem = n % 3;
      if (rem != 0) {
        return false;
      }
      n /= 3;
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
  res = s.isPowerOfThree(num);

  // output
  cout << "\n\nResult: " << endl;
  cout << "Number is " << (res ? "" : "not ") << "a power of three." << endl
       << endl;

  return 0;
}