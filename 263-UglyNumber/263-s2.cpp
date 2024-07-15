#include <iostream>

using namespace std;

class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) {
      return false;
    }
    while (n % 2 == 0) {
      n /= 2;
    }
    while (n % 3 == 0) {
      n /= 3;
    }
    while (n % 5 == 0) {
      n /= 5;
    }
    return n == 1;
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