#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      // swap(s[left], s[right])
      left++;
      right--;
    }
  }
};

int main() {
  // declaration
  Solution s;
  char c;
  vector<char> stack;

  // input
  cout << "\nEnter letters, EOF to stop: \n> ";
  while (cin >> c) {
    stack.push_back(c);
  };
  cout << "\nInput: ";
  for (char letter : stack) {
    cout << letter << " ";
  }

  // processing
  s.reverseString(stack);

  // output
  cout << "\n\nResult: ";
  for (char letter : stack) {
    cout << letter << " ";
  }
  cout << endl << endl;

  return 0;
}