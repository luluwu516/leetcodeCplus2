#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> letters_s(26, 0);
    vector<int> letters_r(26, 0);

    for (int i = 0; i < s.size(); i++) {
      letters_s[int(s[i]) - int('a')]++;
      letters_r[int(t[i]) - int('a')]++;
    }

    for (int i = 0; i < 26; i++) {
      if (letters_s[i] != letters_r[i]) {
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