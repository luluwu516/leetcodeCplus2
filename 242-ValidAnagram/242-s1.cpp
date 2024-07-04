#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    unordered_map<char, int> count;
    for (char c : s) {
      count[c]++;
    }
    for (char c : t) {
      count[c]--;
    }
    for (auto item : count) {
      if (item.second != 0) {
        return false;
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
  cout << "\nEnter a string: ";
  cin >> s;
  cout << "\nEnter another string: ";
  cin >> t;

  res = solution.isAnagram(s, t);

  // output
  cout << "\nResult:\n";
  cout << "The string is " << (res ? "anagram." : "not anagram.") << "\n\n";

  return 0;
}