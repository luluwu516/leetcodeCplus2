#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      //   if (m.count(nums[i]) && abs(i - m[nums[i]]) <= k) {
      //     return true;
      //   }
      //   m[nums[i]] = i;

      if (m[nums[i]] && i + 1 - m[nums[i]] <= k) {
        return true;
      }
      m[nums[i]] = i + 1;
    }

    return false;
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int num, k;
  bool res;

  // input
  cout << "Enter the numbers, or -1 to stop: \n> ";
  cin >> num;
  while (num != -1) {
    nums.push_back(num);
    cout << "> ";
    cin >> num;
  }
  cout << "Enter an interger k: ";
  cin >> k;

  // processing
  res = s.containsNearbyDuplicate(nums, k);

  // output
  cout << "\n\nResult:\n";
  cout << "The array " << (res ? "contains" : "doesn't contain") << " duplicate"
       << endl
       << endl;

  return 0;
}