#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    if (columnNumber == 0) {
      return "";
    }
    columnNumber--;
    return convertToTitle(columnNumber / 26) + (char)('A' + columnNumber % 26);
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