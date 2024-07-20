#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int sumOfNums = 0;
    int len = nums.size();
    int sumOfN = (len * (len + 1)) / 2;

    for (int n : nums) {
      sumOfNums += n;
    }

    return sumOfN - sumOfNums;
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