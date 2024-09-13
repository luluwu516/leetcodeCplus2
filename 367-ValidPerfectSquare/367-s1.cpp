#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPerfectSquare(int num) {
    for (long i = 0; i <= num; i++) {
      if (i * i == num) {
        return true;
      } else if (i * i > num) {
        return false;
      }
    }
    return false;
  }
};

int main() {
  // declaration
  Solution s;
  int num;
  bool res;

  // input
  cout << "\nEnter a number: ";
  cin >> num;

  // processing
  res = s.isPerfectSquare(num);

  // output
  cout << "\n\nResult: \n";
  cout << num << " is " << (res ? "" : "not ") << "a perfect square\n\n";

  return 0;
}