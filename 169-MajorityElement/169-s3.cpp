#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int majority = nums[0];
    int max_count = 0;

    for (int n : nums) {
      map[n]++;
    }

    for (int n : nums) {
      if (map[n] > map[majority]) {
        majority = n;
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