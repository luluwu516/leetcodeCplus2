#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 0; i < n + 1; i++) {
      int count = 0;
      int num = i;
      while (num > 0) {
        num = num & (num - 1);
        count++;
      }
      res[i] = count;
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