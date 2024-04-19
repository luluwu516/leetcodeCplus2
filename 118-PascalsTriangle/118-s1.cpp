#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res = {{1}};
    vector<int> prev = {0, 1, 0};

    for (int i = 1; i < numRows; i++) {
      vector<int> curr;
      for (int j = 0; j < i + 1; j++) {
        curr.push_back(prev[j] + prev[j + 1]);
      }
      res.push_back(curr);
      prev.assign(curr.begin(), curr.end());
      prev.insert(prev.begin(), 0);
      prev.push_back(0);
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
