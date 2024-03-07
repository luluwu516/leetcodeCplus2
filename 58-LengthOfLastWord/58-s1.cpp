#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int count = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != ' ') {
        count++;
      } else if (count && s[i] == ' ') {
        return count;
      }
    }

    return count;
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