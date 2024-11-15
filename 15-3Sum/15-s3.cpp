#include <iostream>
#include <set>
#include <vector>

using namespace std;  // using directive

//
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // declaration
    int len = nums.size(), sum;
    int right, left;
    vector<vector<int>> res;

    // sort the nums
    sort(nums.begin(), nums.end());  // -4 -1 -1 0 1 2

    for (int i = 0; i < len; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;  // skip the dup
      }
      left = i + 1;
      right = len - 1;
      while (left < right) {
        sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          res.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) {
            left++;  // skip the dup
          }
          while (left < right && nums[right] == nums[right - 1]) {
            right--;  // skip the dup
          }
          left++;
          right--;
        } else if (sum > 0) {
          right--;
        } else {
          left++;
        }
      }
    }
    return res;
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