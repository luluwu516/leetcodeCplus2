#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    for (int n : nums1) {
      if (find(nums2.begin(), nums2.end(), n) != nums2.end() &&
          find(res.begin(), res.end(), n) == res.end()) {
        res.push_back(n);
      }
    }
    return res;
  }
};

int main() {
  // declaration
  Solution s;
  int num;
  vector<int> nums1, nums2, res;

  // input
  cout << "\nEnter numbers for array 1: \n> ";
  cin >> num;
  while (num != -1) {
    nums1.push_back(num);
    cout << "> ";
    cin >> num;
  }

  cout << "\nEnter numbers for array 2: \n> ";
  cin >> num;
  while (num != -1) {
    nums2.push_back(num);
    cout << "> ";
    cin >> num;
  }

  // processing
  res = s.intersection(nums1, nums2);

  // output
  cout << "\n\nResult: \n";
  cout << "The intersection of two integer arrays is: ";
  for (int n : res) {
    cout << n << " ";
  }
  cout << endl << endl;

  return 0;
}