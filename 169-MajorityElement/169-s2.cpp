#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int median = nums.size() / 2;
    std::sort(nums.begin(), nums.end());
    return nums[median];
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int num, res;

  // input
  cout << "Enter the numbers, or EOF to stop: \n> ";
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  // processing
  res = s.majorityElement(nums);

  // output
  cout << "\n\nResult:\n";
  cout << "The majority element is " << res << endl << endl;

  return 0;
}