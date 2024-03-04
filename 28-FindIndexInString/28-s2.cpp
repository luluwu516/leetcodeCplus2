#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) {
      return -1;
    }

    for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
      bool flag = false;
      if (haystack[i] == needle[0]) {
        flag = true;
        for (int j = 0; j < needle.size(); j++) {
          if (haystack[i + j] != needle[j]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          return i;
        }
      }
    }

    return -1;
  }
};

int main() {
  // declaration
  Solution s;
  string haystack, needle;
  int index;

  // input
  cout << "\nEnter the first string: ";
  cin >> haystack;

  cout << "Enter the second string: ";
  cin >> needle;

  // processing
  index = s.strStr(haystack, needle);

  // output
  cout << "\nResult: \n";
  if (index != -1) {
    cout << "The first '" << needle << "' occurs at index " << index << endl;
  } else {
    cout << "'" << needle << "' did not occur in '" << haystack << "'\n\n";
  }

  return 0;
}