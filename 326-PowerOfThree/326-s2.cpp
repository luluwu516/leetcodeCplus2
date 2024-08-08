#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }

    for (int i = 0; i < 20; i++) {
      if (pow(3, i) == n) {
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
  res = s.isPowerOfThree(num);

  // output
  cout << "\n\nResult: " << endl;
  cout << "Number is " << (res ? "" : "not ") << "a power of three." << endl
       << endl;

  return 0;
}