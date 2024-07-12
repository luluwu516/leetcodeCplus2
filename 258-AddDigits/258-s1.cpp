#include <iostream>

using namespace std;

class Solution {
 public:
  int addDigits(int num) {
    if (num == 0) {
      return 0;
    } else if (num % 9 == 0) {
      return 9;
    } else {
      return num % 9;
    }
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