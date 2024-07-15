#include <iostream>

using namespace std;

class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) {
      return false;
    } else if (n == 1) {
      return true;
    } else if (n % 2 == 0) {
      return isUgly(n / 2);
    } else if (n % 3 == 0) {
      return isUgly(n / 3);
    } else if (n % 5 == 0) {
      return isUgly(n / 5);
    } else {
      return false;
    }
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int num;
  bool res;

  // input
  cout << "\nEnter an integer: ";
  cin >> num;

  // processing
  res = s.isUgly(num);

  // output
  cout << "\nResult:\n";
  cout << "The number is" << (res ? "" : " not") << " a ugly number" << endl
       << endl;

  return 0;
}