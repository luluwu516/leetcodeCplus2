#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] == 9) {
        digits[i] = 0;
      } else {
        digits[i] += 1;
        return digits;
      }
    }
    if (digits[0] == 0) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  vector<int> digits, result;
  int d;

  // input
  cout << ("Enter list digits, EOF to stop: \n> ");
  while (cin >> d) {
    digits.push_back(d);
    cout << "> ";
  }

  result = s.plusOne(digits);

  // output
  cout << "\n\nResult:\n";
  cout << "The number of the digits plus one is: [ ";
  for (int d : result) {
    cout << d << " ";
  }
  cout << "]\n\n";

  return 0;
}