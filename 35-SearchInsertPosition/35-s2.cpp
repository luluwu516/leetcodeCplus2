#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return left;
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