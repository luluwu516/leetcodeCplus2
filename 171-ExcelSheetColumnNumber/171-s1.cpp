#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int sum = 0;
    for (const char& c : columnTitle) {
      sum = sum * 26 + (c - 'A' + 1);
    }

    return sum;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  string columnTitle;
  int res;

  // input
  cout << ("\nEnter a column title: ");
  cin >> columnTitle;

  res = s.titleToNumber(columnTitle);

  // output
  cout << "\n\nResult:\n";
  cout << "The column number is '" << res << "'" << endl << endl;

  return 0;
}