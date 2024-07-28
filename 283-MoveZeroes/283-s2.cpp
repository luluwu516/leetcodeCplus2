#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int j = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] != 0) {
        nums[j] = nums[i];
        j++;
      }
    }
    for (int i = j; i < size; i++) {
      nums[i] = 0;
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