#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int majority = nums[0];
    int count = 0;

    for (int n : nums) {
      if (count == 0) {
        majority = n;
        count++;
      } else if (majority == n) {
        count++;
      } else {
        count--;
      }
    }

    return majority;
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