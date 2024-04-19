#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;

    for (int i = 1; i <= numRows; i++) {
      res.push_back(generateRows(i));
    }
    return res;
  }

  vector<int> generateRows(int row) {
    vector<int> newRow;
    newRow.push_back(1);
    int res = 1;

    for (int col = 1; col < row; col++) {
      res = res * (row - col);
      res /= col;
      newRow.push_back(res);
    }

    return newRow;
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
