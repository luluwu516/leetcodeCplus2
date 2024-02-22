#include "iostream"
#include "vector"

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    } else if (strs.size() == 1) {
      return strs[0];
    }

    for (int i = 0; i < strs[0].size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
          return strs[0].substr(0, i);
        }
      }
    }

    return strs[0];
  }
};

int main() {
  // declaration
  vector<string> strs;
  string input, prefix;
  Solution s;

  // input
  cout << "Enter a list of strings separated by new line, -1 to stop: \n> ";
  while (cin >> input) {
    if (input == "-1") {
      break;
    }
    cout << "> ";
    strs.push_back(input);
  }

  // processing
  prefix = s.longestCommonPrefix(strs);

  // output
  if (!prefix.empty()) {
    cout << "\nResult: " << prefix << endl;
  } else {
    cout << "There is no common prefix among the input strings." << endl;
  }

  return 0;
}