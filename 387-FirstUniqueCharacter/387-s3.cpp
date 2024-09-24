#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    int len = s.size();
    vector<int> stack(26, 0);
    for (char c : s) {
      stack[c - 'a']++;
    }

    for (int i = 0; i < len; i++) {
      if (stack[s[i] - 'a'] == 1) {
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