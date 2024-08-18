#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int n) {
    for (int i = 0; i < 16; i++) {
      int powerOfFour = pow(4, i);
      if (powerOfFour == n) {
        return true;
      }
      if (powerOfFour > n) {
        return false;
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
  res = s.isPowerOfFour(num);

  // output
  cout << "\n\nResult: " << endl;
  cout << "Number is " << (res ? "" : "not ") << "a power of four." << endl
       << endl;

  return 0;
}