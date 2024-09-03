#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int l1 = 0, l2 = 0, r1 = nums1.size(), r2 = nums2.size();
    while (l1 < r1 && l2 < r2) {
      if (nums1[l1] < nums2[l2]) {
        l1++;
      } else if (nums2[l2] < nums1[l1]) {
        l2++;
      } else {
        if (res.size() == 0 || res.back() != nums1[l1])
          res.push_back(nums1[l1]);
        l1++;
        l2++;
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
  cout << "\nEnter numbers for array 1 (-1 to stop): \n> ";
  cin >> num;
  while (num != -1) {
    nums1.push_back(num);
    cout << "> ";
    cin >> num;
  }

  cout << "\nEnter numbers for array 2 (-1 to stop): \n> ";
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