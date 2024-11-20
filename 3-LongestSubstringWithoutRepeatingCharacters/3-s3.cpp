#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }

    int left = 0, right, res = 0;
    int n = s.size();
    vector<int> counter(128);

    for (right = 0; right < n; right++) {
      counter[s[right]]++;
      while (counter[s[right]] > 1) {
        counter[s[left]]--;
        left++;
      }
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