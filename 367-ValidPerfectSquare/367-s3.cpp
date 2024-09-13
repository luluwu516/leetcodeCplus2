#include <cmath>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPerfectSquare(int num) {
    double square = sqrt(num);
    return square == (int)square;
  }
};

int main() {
  // declaration
  Solution s;
  int num;
  bool res;

  // input
  cout << "\nEnter a number: ";
  cin >> num;

  // processing
  res = s.isPerfectSquare(num);

  // output
  cout << "\n\nResult: \n";
  cout << num << " is " << (res ? "" : "not ") << "a perfect square\n\n";

  return 0;
}