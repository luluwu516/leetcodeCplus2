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

    string prefix = strs[0];
    cout << "initial prefix: " << prefix << endl;

    for (int i = 1; i < strs.size(); i++) {
      int count = 0;
      while (prefix[count] && strs[i][count] &&
             prefix[count] == strs[i][count]) {
        count++;
      }
      prefix.erase(count);
      if (prefix.empty()) {
        break;
      }
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