#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);
    res[0].push_back(1);
    for (int i = 1; i < numRows; i++) {
      res[i].push_back(1);
      for (int j = 1; j < i; j++) {
        res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
      }
      res[i].push_back(1);
    }

    return res;
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
