#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    int nums1Size = nums1.size(), nums2Size = nums2.size();
    while (i < nums1Size && j < nums2Size) {
      if (nums1[i] == nums2[j]) {
        res.push_back(nums1[i]);
        i++;
        j++;
      } else if (nums1[i] < nums2[j]) {
        i++;
      } else {
        j++;
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