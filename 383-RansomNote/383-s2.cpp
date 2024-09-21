#include <iostream>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int letters[26] = {0};

    for (int i = 0; i < magazine.size(); i++) {
      letters[magazine[i] - 'a']++;
    }

    for (int i = 0; i < ransomNote.size(); i++) {
      letters[ransomNote[i] - 'a']--;
      if (letters[ransomNote[i] - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  // declaration
  Solution s;
  string ransomNote, magazine;
  bool res;

  // input
  cout << "\nEnter ransom noter: ";
  cin >> ransomNote;
  cout << "Enter magazine: ";
  cin >> magazine;

  // processing
  res = s.canConstruct(ransomNote, magazine);

  // output
  cout << "\n\nResult: \n";
  cout << "Each letter in magazine can " << (res ? "" : "not ")
       << "only be used once in ransom note\n\n";

  return 0;
}