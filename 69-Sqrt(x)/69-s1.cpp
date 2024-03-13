#include <iostream>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    int i;
    for (i = 1; i < x; i++) {
      if (x / i < i) {
        return i - 1;
      }
    }
    return i - 1;
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