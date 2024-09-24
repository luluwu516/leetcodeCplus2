#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> m;
    for (char c : s) {
      m[c]++;
    }

    for (int i = 0; i < s.length(); i++) {
      if (m[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  // declaration
  Solution s;
  string str;
  int res;

  // input
  cout << "\nEnter ransom noter: ";
  cin >> str;

  // processing
  res = s.firstUniqChar(str);

  // output
  cout << "\nResult: \n";
  if (res != -1) {
    cout << "The character " << str[res] << " at index " << res
         << " is the first character that does not occur at any other "
            "index.\n\n";
  } else {
    cout << "The non-repeating character does not exist.\n\n";
  }

  return 0;
}