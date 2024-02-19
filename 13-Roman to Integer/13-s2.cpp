#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> roman_to_int;
    roman_to_int['I'] = 1;
    roman_to_int['V'] = 5;
    roman_to_int['X'] = 10;
    roman_to_int['L'] = 50;
    roman_to_int['C'] = 100;
    roman_to_int['D'] = 500;
    roman_to_int['M'] = 1000;

    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
      if (i < s.size() - 1 && roman_to_int[s[i]] < roman_to_int[s[i + 1]]) {
        sum -= roman_to_int[s[i]];
      } else {
        sum += roman_to_int[s[i]];
      }
    }
    return sum;
  }
};

int main() {
  // Declaration
  Solution s;
  string roman_numeral;

  // Input
  cout << "Enter Roman numeral (I, V, X, L, C, D, or M): ";
  cin >> roman_numeral;

  // Processing and Output
  cout << "Result: " << s.romanToInt(roman_numeral) << endl;

  return 0;
}