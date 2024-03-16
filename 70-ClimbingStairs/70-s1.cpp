#include <iostream>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    if (n < 2) {
      return 1;
    }
    int prev = 1, curr = 1;
    int temp;

    for (int i = 2; i < n + 1; i++) {
      temp = curr;
      curr += prev;
      prev = temp;
    }

    return curr;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int num, result;

  // input
  cout << ("\nEnter how many steps in a staircase: ");
  cin >> num;

  result = s.climbStairs(num);

  // output
  cout << "\n\nResult:\n";
  cout << "There are " << result << " ways to climb to the top." << endl
       << endl;

  return 0;
}
