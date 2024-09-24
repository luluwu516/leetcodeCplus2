#include <iostream>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    int first, last;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      first = s.find(c);
      last = s.rfind(c);
      if (first == last) {
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