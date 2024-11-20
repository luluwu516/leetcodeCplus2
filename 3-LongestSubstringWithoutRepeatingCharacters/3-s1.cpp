#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> m;
    int count = 0, res = 0, n = s.size();
    for (int i = 0; i < n; i++) {
      count++;
      if (m[s[i]]) {
        i = m[s[i]] - 1;
        count = 0;
        m.clear();
      } else {
        m[s[i]] = i + 1;
      }
      res = max(res, count);
    }
    return res;
  }
};

int main() {
  // declaration
  Solution s;
  string input;
  int res;

  // input
  cout << "\nEnter a string: ";
  cin >> input;

  // processing
  res = s.lengthOfLongestSubstring(input);

  // output
  cout << "\n\nResult:\n";
  cout
      << "The length of the longest substring without repeating characters is: "
      << res << "\n\n";

  return 0;
}

// Sample output:
/*

Enter a string: abcabcbb


Result:
The length of the longest substring without repeating characters is: 3

*/