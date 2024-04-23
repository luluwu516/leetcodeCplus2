#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> res = {{1}};
    vector<int> prev = {0, 1, 0};

    for (int i = 1; i < rowIndex + 1; i++) {
      vector<int> curr;
      for (int j = 0; j < i + 1; j++) {
        curr.push_back(prev[j] + prev[j + 1]);
      }
      res.push_back(curr);
      prev.assign(curr.begin(), curr.end());
      prev.insert(prev.begin(), 0);
      prev.push_back(0);
    }

    return res[rowIndex];
  }
};

int main() {
  // declaration
  Solution s = Solution();
  int row;
  vector<int> result;

  // input
  cout << "Enter the row: ";
  cin >> row;

  // processing
  result = s.getRow(row);

  // output
  cout << "\n\nResult:\n";
  for (auto c : result) {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}
