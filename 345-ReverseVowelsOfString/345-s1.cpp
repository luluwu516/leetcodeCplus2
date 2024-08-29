#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      char l = tolower(s[left]);
      if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') {
        char r = tolower(s[right]);
        while (!(r == 'a' || r == 'e' || r == 'i' || r == 'o' || r == 'u')) {
          right--;
          r = tolower(s[right]);
        }
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        right--;
      }
      left++;
    }
    return s;
  }
};

int main() {
  // declaration
  Solution s;
  char c;
  string str, res;

  // input
  cout << "\nEnter a string: ";
  cin >> str;

  // processing
  res = s.reverseVowels(str);

  // output
  cout << "\n\nResult: \n";
  cout << "Reverse only all the vowels in the string: " << res << endl << endl;

  return 0;
}