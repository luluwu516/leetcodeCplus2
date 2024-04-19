#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) {
      return {{1}};
    }

    vector<vector<int>> prevRows = generate(numRows - 1);
    vector<int> newRow(numRows, 1);

    for (int i = 1; i < numRows - 1; i++) {
      newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
    }

    prevRows.push_back(newRow);

    return prevRows;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int row;
  vector<vector<int>> result;

  // input
  cout << "Enter the row: ";
  cin >> row;

  // processing
  result = s.generate(row);

  // output
  cout << "\n\nResult:\n";
  for (auto r : result) {
    for (auto c : r) {
      cout << c << " ";
    }
    cout << endl;
  }

  return 0;
}
