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
    set<vector<int>> res;

    // sort the nums
    sort(nums.begin(), nums.end());  // -4 -1 -1 0 1 2

    for (int i = 0; i < len; i++) {
      left = i + 1;
      right = len - 1;
      while (left < right) {
        sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          res.insert({nums[i], nums[left], nums[right]});
          left++;
          right--;
        } else if (sum > 0) {
          right--;
        } else {
          left++;
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