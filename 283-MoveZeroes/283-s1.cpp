#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int beginning = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        int t = nums[i];
        nums[i] = nums[beginning];
        nums[beginning] = t;
        // swap(nums[beginning], nums[i]);
        beginning++;
      }
    }
  }
};

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums;
  int num, res;

  // input
  cout << "\nEnter n, EOF to stop: \n> ";
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  // processing
  s.moveZeroes(nums);

  // output
  cout << "\n\nResult:\n";
  for (int n : nums) {
    cout << n << " ";
  }
  cout << endl << endl;

  return 0;
}