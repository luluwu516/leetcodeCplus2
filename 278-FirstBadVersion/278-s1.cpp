#include <iostream>

using namespace std;

class Solution {
 public:
  Solution(int bad) : badVersion(bad) {}
  int firstBadVersion(int n) {
    int left = 1, right = n, mid;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  bool isBadVersion(int version) { return version == badVersion; }

 private:
  int badVersion;
};

int main() {
  // declaration
  int bad;
  cout << "Enter the bad version: ";
  cin >> bad;
  Solution s = Solution(bad);
  int num, res;

  // input
  cout << "\nEnter n: ";
  cin >> num;

  // processing
  res = s.firstBadVersion(num);

  // output
  cout << "\nResult\n";
  cout << "Version " << res << " is the first bad version" << endl << endl;

  return 0;
}