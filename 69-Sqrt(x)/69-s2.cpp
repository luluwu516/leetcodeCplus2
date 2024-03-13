#include <iostream>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    int left = 1, right = x;
    int mid, divide;

    while (left < right) {
      mid = (left + (long)right) / 2 + 1;
      divide = x / mid;
      if (divide == mid) {
        return divide;
      } else if (divide > mid) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int num, result;

  // input
  cout << ("\nEnter a number: ");
  cin >> num;

  result = s.mySqrt(num);

  // output
  cout << "\n\nResult:\n";
  cout << "The square root of " << num << " is " << result << endl << endl;

  return 0;
}