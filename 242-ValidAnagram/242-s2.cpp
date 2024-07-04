#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};

int main() {
  // declaration
  Solution solution = Solution();
  string s, t;
  bool res;

  // input
  cout << "\nEnter a string: ";
  cin >> s;
  cout << "\nEnter another string: ";
  cin >> t;

  res = solution.isAnagram(s, t);

  // output
  cout << "\nResult:\n";
  cout << "The strings are " << (res ? "anagram" : "not anagram") << "\n\n";

  return 0;
}