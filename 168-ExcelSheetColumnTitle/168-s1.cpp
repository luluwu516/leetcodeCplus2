#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string res = "";
    while (columnNumber > 0) {
      columnNumber--;
      res = (char)('A' + columnNumber % 26) + res;
      columnNumber /= 26;
    }

    return res;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int columnNumber;
  string res;

  // input
  cout << ("\nEnter a number: ");
  cin >> columnNumber;

  res = s.convertToTitle(columnNumber);

  // output
  cout << "\n\nResult:\n";
  cout << "The corresponding column title is '" << res << "'" << endl << endl;

  return 0;
}