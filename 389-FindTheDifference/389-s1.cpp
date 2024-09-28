#include <iostream>
// #include <unordered_map>

using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    // unordered_map<char, int> lettersCounter;
    int len = s.size(), i;
    // int lettersCounter[26] = {0};
    vector<int> lettersCounter(26, 0);
    for (i = 0; i < len; i++) {
      lettersCounter[s[i] - 'a']++;
      lettersCounter[t[i] - 'a']--;
    }
    lettersCounter[t[i] - 'a']--;

    for (i = 0; i < 26; i++) {
      if (lettersCounter[i] != 0) {
        return (char)(i + 97);
      }
    }
    return (char)(i + 97);
  }
};

int main() {
  // declaration
  Solution s;
  string str1, str2;
  char res;

  // input
  cout << "\nEnter string 1: ";
  cin >> str1;
  cout << "Enter string 2: ";
  cin >> str2;

  // processing
  res = s.findTheDifference(str1, str2);

  // output
  cout << "\nResult: \n";
  cout << "'" << res << "' is the letter that was added\n\n";

  return 0;
}