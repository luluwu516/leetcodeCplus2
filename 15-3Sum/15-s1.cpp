#include <iostream>
#include <set>
#include <vector>

using namespace std;  // using directive

// brute force
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> res;

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        for (int k = j + 1; k < len; k++) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            vector<int> temp = {nums[i], nums[j], nums[k]};
            res.insert(temp);
          }
        }
      }
    }
    return vector<vector<int>>(res.begin(), res.end());
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int input;
  vector<vector<int>> res;

  // input
  cout << "\nEnter numbers, EOF to stop: \n> ";
  while (cin >> input) {
    nums.push_back(input);
  }

  // processing
  res = s.threeSum(nums);

  // output
  cout << "\n\nResult:\n";
  for (auto& triplet : res) {
    cout << "[ ";
    for (auto& n : triplet) {
      cout << n << " ";
    }
    cout << "]\n";
  }

  return 0;
}

// Sample Output:
/*

Enter numbers, EOF to stop:
> -1 0 1 2 -1 -4
^D

Result:
[ -1 -1 2 ]
[ -1 0 1 ]

*/