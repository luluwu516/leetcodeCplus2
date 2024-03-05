#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= target) {
        return i;
      }
    }
    return nums.size();
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int input, target, result;

  // input
  cout << "Enter list numbers, -1 to stop: \n> ";
  cin >> input;
  while (input != -1) {
    nums.push_back(input);
    cout << "> ";
    cin >> input;
  }

  cout << "\nEnter the target: ";
  cin >> target;

  result = s.searchInsert(nums, target);

  // output
  cout << "\n\nResult:\n";
  cout << "The target \"" << target << "\" should be inserted at index "
       << result << endl
       << endl;

  return 0;
}