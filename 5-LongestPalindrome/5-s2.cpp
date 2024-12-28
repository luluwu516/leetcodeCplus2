#include <iostream>  // preprocessor directive
#include <string>

using namespace std;  // using directive

// dynamic programming solution
class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (len < 2) {
      return s;
    }

    int start = 0;
    int end = 0;
    int maxLen = 1;
    vector<vector<bool>> dp(len, vector<bool>(len, false));

    for (int i = 0; i < len; i++) {
      dp[i][i] = true;
      for (int j = 0; j < i; j++) {
        if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
          dp[j][i] = true;
          if (i - j + 1 > maxLen) {
            maxLen = i - j + 1;
            start = j;
            end = i;
          }
        }
      }
    }

    return s.substr(start, end - start + 1);
  }
};

int main() {
  // declaration
  Solution s;
  string str, res;

  // input
  cout << "\nEnter a string: ";
  cin >> str;

  // processing
  res = s.longestPalindrome(str);

  // output
  cout << "\n\nResult:\n";
  cout << "The longest palindromic substring is \"" << res << "\"\n\n";

  return 0;
}