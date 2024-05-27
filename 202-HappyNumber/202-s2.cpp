#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    vector<int> seen;
    return helper(n, seen);
  }

  int helper(int n, vector<int> &seen) {
    if (n == 1) {
      return true;
    }
    for (int &num : seen) {
      if (num == n) {
        return false;
      }
    }

    seen.push_back(n);
    int sum = 0;
    int digit;
    while (n > 0) {
      digit = n % 10;
      sum += (digit * digit);
      n /= 10;
    }
    return helper(sum, seen);
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