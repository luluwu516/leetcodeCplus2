#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    vector<int> nums;

    while (i < m && j < n) {
      if (nums1[i] > nums2[j]) {
        nums.push_back(nums2[j]);
        j++;
      } else {
        nums.push_back(nums1[i]);
        i++;
      }
    }
    while (i < m) {
      nums.push_back(nums1[i]);
      i++;
    }
    while (j < n) {
      nums.push_back(nums2[j]);
      j++;
    }
    for (int k = 0; k < m + n; k++) {
      nums1[k] = nums[k];
    }
  }
};

void printList(vector<int>& nums) {
  for (int n : nums) {
    cout << n << " ";
  }
  cout << endl;
}

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums1, nums2;
  int num, nums1_size;

  // input
  cout << "nums1:\n";
  cout << ("Enter numbers, -1 to stop: \n> ");
  cin >> num;
  while (num != -1) {
    nums1.push_back(num);
    cout << "> ";
    cin >> num;
  }
  nums1_size = nums1.size();

  cout << "\nnums2:\n";
  cout << ("Enter numbers, -1 to stop: \n> ");
  cin >> num;
  while (num != -1) {
    nums2.push_back(num);
    cout << "> ";
    cin >> num;
  }

  for (int i = 0; i < nums2.size(); i++) {
    nums1.push_back(0);
  }

  cout << "\nOriginal list: \n";
  cout << "nums1: ";
  printList(nums1);
  cout << "nums2: ";
  printList(nums2);

  // processing
  s.merge(nums1, nums1_size, nums2, nums2.size());

  // output
  cout << "\n\nResult:\n";
  printList(nums1);
  cout << endl;

  return 0;
}
