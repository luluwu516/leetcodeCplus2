#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (isVowel(s[left])) {
        while (!isVowel(s[right])) {
          right--;
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