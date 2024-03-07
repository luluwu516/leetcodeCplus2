#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int lastWordEnd, lastWordStart;
    int i = s.size() - 1;

    lastWordEnd = i;
    while (i >= 0 && s[i] == ' ') {
      i--;
    }
    lastWordEnd = i;

    while (i >= 0 && s[i] != ' ') {
      i--;
    }
    lastWordStart = i;

    return lastWordEnd - lastWordStart;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  string str;
  int result;

  // input
  cout << "\nEnter a string: ";
  cin >> str;

  result = s.lengthOfLastWord(str);

  // output
  cout << "\nResult:\n";
  cout << "The length of the last word is " << result << "\n\n";

  return 0;
}