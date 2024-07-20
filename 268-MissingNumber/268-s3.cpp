#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (i != nums[i]) {
        return i;
      }
    }
    return len;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums;
  int num, res;

  // input
  cout << "\nEnter integers, EOF to stop: \n> ";
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  };

  // processing
  res = s.missingNumber(nums);

  // output
  cout << "\n\nResult:\n";
  cout << "The missing number is " << res << endl << endl;

  return 0;
}