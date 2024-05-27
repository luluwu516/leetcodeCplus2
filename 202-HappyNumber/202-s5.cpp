#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    int slow, fast;
    slow = sumOfSquares(n);
    fast = sumOfSquares(sumOfSquares(n));
    while (fast != 1 && fast != slow) {
      slow = sumOfSquares(slow);
      fast = sumOfSquares(sumOfSquares(fast));
    }
    return fast == 1;
  }

  int sumOfSquares(int n) {
    int sum = 0;
    int digit;
    while (n > 0) {
      digit = n % 10;
      sum += (digit * digit);
      n /= 10;
    }
    return sum;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int num;
  bool res;

  // input
  cout << "\nEnter a number: ";
  cin >> num;

  res = s.isHappy(num);

  // output
  cout << "\nResult:\n";
  cout << "The number is " << (res ? "a" : "not a") << " happy number\n\n";

  return 0;
}