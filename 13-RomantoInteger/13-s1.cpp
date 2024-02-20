#include <iostream>
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

    // Another way
    // unordered_map<char, int> romanValues = {
    //     {'I', 1},
    //     {'V', 5},
    //     {'X', 10},
    //     {'L', 50},
    //     {'C', 100},
    //     {'D', 500},
    //     {'M', 1000}
    // };

    int sum;
    sum = roman_to_int[s[0]];

    for (int i = 1; i < s.size(); i++) {
      if (s[i] == 'V' && s[i - 1] == 'I') {
        sum -= 2;
      } else if (s[i] == 'X' && s[i - 1] == 'I') {
        sum -= 2;
      } else if (s[i] == 'L' && s[i - 1] == 'X') {
        sum -= 20;
      } else if (s[i] == 'C' && s[i - 1] == 'X') {
        sum -= 20;
      } else if (s[i] == 'D' && s[i - 1] == 'C') {
        sum -= 200;
      } else if (s[i] == 'M' && s[i - 1] == 'C') {
        sum -= 200;
      }
      sum += roman_to_int[s[i]];
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