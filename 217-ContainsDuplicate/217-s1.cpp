#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for (int n : nums) {
      s.insert(n);
    }
    return s.size() != nums.size();
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums;
  int num;
  bool res;

  // input
  cout << "Enter the numbers, or EOF to stop: \n> ";
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  // processing
  res = s.containsDuplicate(nums);

  // output
  cout << "\n\nResult:\n";
  cout << "The array " << (res ? "contains" : "doesn't contain") << "duplicate"
       << endl
       << endl;

  return 0;
}