#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (int n : nums) {
      mp[n]++;
    }

    for (auto pair : mp) {
      if (pair.second == 1) {
        return pair.first;
      }
    }

    return 0;
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