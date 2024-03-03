#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());

    return nums.size();
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int num, val, dupCount;

  // input
  cout << "Enter list numbers, -1 to stop: \n> ";
  cin >> num;
  while (num != -1) {
    nums.push_back(num);
    cout << "> ";
    cin >> num;
  }

  cout << "\nEnter the element to remove: ";
  cin >> val;

  // processing
  dupCount = s.removeElement(nums, val);

  // output
  cout << "\n\nResult:\n";
  cout << dupCount << " duplicates and nums = [";
  for (int i = 0; i < dupCount; i++) {
    cout << nums[i] << " ";
  }
  cout << "]\n";

  return 0;
}