#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    for (int i = 0; i < s.size(); i++) {
      size_t pos = t.find(s[i]);
      if (pos > t.size()) {
        return false;
      }
      t = t.substr(pos + 1);
    }

    return true;
  }
};

int main() {
  // declaration
  Solution s;
  string str1, str2;
  bool res;

  // input
  cout << "\nEnter string 1: ";
  cin >> str1;
  cout << "Enter string 2: ";
  cin >> str2;

  // processing
  res = s.isSubsequence(str1, str2);

  // output
  cout << "\nResult: \n";
  cout << "'s' is" << (res ? "" : " not")
       << " a new string that is formed from 't' by deleting some (can be "
          "none) of the characters\n\n";

  return 0;
}