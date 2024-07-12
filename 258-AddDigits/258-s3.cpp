#include <iostream>

using namespace std;

class Solution {
 public:
  int addDigits(int num) {
    if (num < 10) {
      return num;
    }
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }

    return addDigits(sum);
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