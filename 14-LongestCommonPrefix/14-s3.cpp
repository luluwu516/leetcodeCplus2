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

    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    string prefix = "";

    for (int i = 0; i < first.size(); i++) {
      if (first[i] == last[i]) {
        prefix += first[i];
      } else
        return prefix;
    }
    return prefix;
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