#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    int digitA, digitB, sum;

    while (i >= 0 || j >= 0 || carry > 0) {
      if (i >= 0) {
        digitA = (int)a[i] - '0';
      } else {
        digitA = 0;
      }

      if (j >= 0) {
        digitB = (int)b[j] - '0';
      } else {
        digitB = 0;
      }

      sum = digitA + digitB + carry;
      carry = sum / 2;
      sum = sum % 2;

      result.insert(0, to_string(sum));
      i--;
      j--;
    }

    return result;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  string digits_a, digits_b, result;

  // input
  cout << ("Enter a binary number: ");
  cin >> digits_a;

  cout << ("Enter another binary number: ");
  cin >> digits_b;

  // processing
  result = s.addBinary(digits_a, digits_b);

  // output
  cout << "\n\nResult:\n";
  cout << "The sum of two binary numbers is: " << result << endl;

  return 0;
}