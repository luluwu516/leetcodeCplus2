#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    vector<char> s_index, t_index;

    for (char c : s) {
      s_index.push_back(findIndex(s, c));
    }
    for (char c : t) {
      t_index.push_back(findIndex(t, c));
    }

    for (int i = 0; i < s.length(); i++) {
      if (s_index[i] != t_index[i]) {
        return false;
      }
    }

    return true;
  }

  int findIndex(string s, char c) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == c) {
        return i;
      }
    }
    return -1;
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
  cout << "\nEnter another string: ";
  cin >> t;

  // processing
  res = solution.isIsomorphic(s, t);

  // output
  cout << "\nResult:\n";
  cout << "Two strings are" << (res ? "isomorphic" : "not isomorphic") << endl;

  return 0;
}