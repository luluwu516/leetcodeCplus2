#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    int n = s.size(), left = 0, res = 0;
    unordered_set<char> seen;

    for (int right = 0; right < n; right++) {
      while (seen.find(s[right]) != seen.end()) {
        seen.erase(s[left]);
        left++;
      }
      seen.insert(s[right]);
      res = max(res, right - left + 1);
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