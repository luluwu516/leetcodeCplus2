#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 1; i < n + 1; i++) {
      res[i] = 1 + res[i & (i - 1)];
    }
    return res;
  }
};

int main() {
  // declaration
  Solution s;
  int n;
  vector<int> res;

  // input
  cout << "\nEnter an integer: ";
  cin >> n;

  // processing
  res = s.countBits(n);

  // output
  cout << "\n\nResult: " << endl;
  for (int num : res) {
    cout << num << " ";
  }
  cout << endl << endl;

  return 0;
}