#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    vector<int> stack;
    int size = nums.size(), notZero = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] != 0) {
        stack.push_back(nums[i]);
        notZero++;
      }
    }
    for (int i = 0; i < size; i++) {
      if (i < notZero) {
        nums[i] = stack[i];
      } else {
        nums[i] = 0;
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