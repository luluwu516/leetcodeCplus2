#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int sumS = 0, sumT = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        sumS += s[i];
        sumT += t[i];
    }
    sumT += t[len];

    return (char)(sumT - sumS);
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