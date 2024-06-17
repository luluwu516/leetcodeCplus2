#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) != m.end() && abs(m[nums[i]] - i) <= k) {
        return true;
      }
      m[nums[i]] = i;
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