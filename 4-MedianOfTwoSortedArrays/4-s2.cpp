#include <iostream>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();

    if (n1 > n2) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int n = n1 + n2;
    int left = (n + 1) / 2;  // get the left partition size
    int low = 0, high = n1;

    while (low <= high) {
      int mid1 = (low + high) / 2;  // get mid index for nums1
      int mid2 = left - mid1;       // get mid index for nums2

      int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

      // determine values of l1, l2, r1, and r2
      if (mid1 < n1) r1 = nums1[mid1];
      if (mid2 < n2) r2 = nums2[mid2];
      if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
      if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

      if (l1 <= r2 && l2 <= r1) {
        // the left partition is correct
        if (n % 2 == 1) {
          return max(l1, l2);
        } else {
          return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
      } else if (l1 > r2) {
        // move towards the left side of nums1
        high = mid1 - 1;
      } else {
        // move towards the right side of nums1
        low = mid1 + 1;
      }
    }

    return 0;
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