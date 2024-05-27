#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> seen;
    int sum = 0, digit;
    while (sum != 1) {
      sum = 0;
      while (n > 0) {
        digit = n % 10;
        sum += (digit * digit);
        n /= 10;
      }
      if (seen.find(sum) != seen.end()) {
        return false;
      }
      seen.insert(sum);
      n = sum;
    }
    return true;
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