#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int num;
  bool res;

  // input
  cout << "Enter the numbers, or EOF to stop: \n> ";
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  // processing
  res = s.containsDuplicate(nums);

  // output
  cout << "\n\nResult:\n";
  cout << "The array " << (res ? "contains" : "doesn't contain") << "duplicate"
       << endl
       << endl;

  return 0;
}