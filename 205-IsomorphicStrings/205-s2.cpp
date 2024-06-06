#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    int len = s.length();

    vector<int> indexS(5000, 0);
    vector<int> indexT(5000, 0);

    for (int i = 0; i < len; i++) {
      if (indexS[s[i]] != indexT[t[i]]) {
        return false;
      }
      indexS[s[i]] = i + 1;
      indexT[t[i]] = i + 1;
    }

    return true;
  }
};

int main() {
  // declaration
  Solution solution = Solution();
  string s, t;
  bool res;

  // input
  cout << "\nEnter a string      : ";
  cin >> s;
  cout << "Enter another string: ";
  cin >> t;

  // processing
  res = solution.isIsomorphic(s, t);

  // output
  cout << "\nResult:\n";
  cout << "Two strings are " << (res ? "isomorphic" : "not isomorphic") << endl;

  return 0;
}