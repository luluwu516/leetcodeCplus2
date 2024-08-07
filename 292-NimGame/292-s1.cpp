#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canWinNim(int n) { return n % 4 != 0; }
};

int main() {
  // declaration
  Solution s = Solution();
  int n;
  bool res;

  // input
  cout << "\nEnter the number of stones in the heap: ";
  cin >> n;

  // processing
  res = s.canWinNim(n);

  // output
  cout << "\n\nResult:\n";
  cout << "You can" << (res ? "" : " not") << " win the game." << endl << endl;

  return 0;
}