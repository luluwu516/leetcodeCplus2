#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> m;
    vector<int> res;
    for (int n : nums1) {
      m[n]++;
    }
    for (int n : nums2) {
      if (m[n]) {
        res.push_back(n);
        m[n]--;
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