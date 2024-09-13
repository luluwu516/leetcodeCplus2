#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPerfectSquare(int num) {
    int low = 0, high = num;
    while (low <= high) {
      long mid = low + (high - low) / 2;
      long square = mid * mid;
      if (square == num) {
        return true;
      } else if (square > num) {
        high = mid - 1;
      } else {
        low = mid + 1;
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