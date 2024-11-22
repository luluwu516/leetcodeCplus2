#include <iostream>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();
    vector<int> nums;

    while (it1 != nums1.end() && it2 != nums2.end()) {
      if (*it1 > *it2) {
        nums.push_back(*it2);
        it2++;
      } else {
        nums.push_back(*it1);
        it1++;
      }
    }
    while (it1 != nums1.end()) {
      nums.push_back(*it1);
      it1++;
    }
    while (it2 != nums2.end()) {
      nums.push_back(*it2);
      it2++;
    }

    int n = nums.size();
    int median = n / 2;

    return n % 2 ? nums[median] : (float)(nums[median] + nums[median - 1]) / 2;
  }
};

int main() {
  // declaration
  Solution s;
  vector<int> nums1, nums2;
  int input;
  float res;

  // input
  cout << "\nEnter numbers for num1, -1 to stop: \n> ";
  cin >> input;
  while (input != -1) {
    nums1.push_back(input);
    cin >> input;
  }

  cout << "\nEnter numbers for num2, -1 to stop: \n> ";
  cin >> input;
  while (input != -1) {
    nums2.push_back(input);
    cin >> input;
  }

  // processing
  res = s.findMedianSortedArrays(nums1, nums2);

  // output
  cout << "\n\nResult:\n";
  cout << "The median of the two sorted arrays: " << res << "\n\n";

  return 0;
}