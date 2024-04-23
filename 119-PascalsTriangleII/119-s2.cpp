#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;
    res.push_back(1);
    long val = 1;

    for (int i = 1; i < rowIndex + 1; i++) {
      val *= (rowIndex + 1 - i);
      val /= i;
      res.push_back(val);
    }

    return res;
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
