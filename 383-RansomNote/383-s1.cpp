#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> hash;
    for (char& c : magazine) {
      hash[c]++;
    }

    for (char& c : ransomNote) {
      hash[c]--;
      if (hash[c] < 0) {
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