#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int x = 0;
    for (int n : nums) {
      x ^= n;
    }
    return x;
  }
};

int main() {
  // declaration
  vector<int> nums;
  int input, res;
  Solution s;

  // input
  cout << "Enter the prices, EOF to stop: \n> ";
  while (cin >> input) {
    cout << "> ";
    nums.push_back(input);
  }

  // processing
  res = s.singleNumber(nums);

  // output
  cout << "\n\nResult: " << endl;
  cout << "Number " << res << " only appears one time" << endl;

  return 0;
}