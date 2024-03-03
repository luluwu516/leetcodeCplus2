#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }

    int unique = 0;
    set<int> nums_set(nums.begin(), nums.end());

    for (auto it = nums_set.begin(); it != nums_set.end(); it++, unique++) {
      nums[unique] = *it;
    }

    return nums_set.size();
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int num, uniqueNumCount;

  // input
  cout << ("Enter list numbers, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  // processing
  uniqueNumCount = s.removeDuplicates(nums);

  // output
  cout << "\n\nResult:\n";
  cout << uniqueNumCount << " unique number(s). nums = [";
  for (int i = 0; i < uniqueNumCount; i++) {
    cout << nums[i];
  }
  cout << "]\n";

  return 0;
}