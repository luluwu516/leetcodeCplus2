#include <iostream>

using namespace std;

class Solution {
 public:
  int addDigits(int num) {
    while (num > 9) {
      int sum = 0;
      sum += num % 10;
      num /= 10;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      num = sum;
    }

    return num;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int num, res;

  // input
  cout << "\nEnter an integer: ";
  cin >> num;

  // processing
  res = s.addDigits(num);

  // output
  cout << "\nAfter repeatedly adding all its digits until the result has only "
          "one digit:\n";
  cout << "Result: " << res << endl << endl;

  return 0;
}