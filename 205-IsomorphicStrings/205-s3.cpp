#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mapS, mapT;

    for (int i = 0; i < s.size(); ++i) {
      char charS = s[i];
      char charT = t[i];

      if (mapS.find(charS) == mapS.end()) {
        mapS[charS] = charT;
      } else {
        if (mapS[charS] != charT) {
          return false;
        }
      }

      if (mapT.find(charT) == mapT.end()) {
        mapT[charT] = charS;
      } else {
        if (mapT[charT] != charS) {
          return false;
        }
      }
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