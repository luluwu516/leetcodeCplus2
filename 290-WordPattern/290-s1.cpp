#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> split(string words) {
    vector<string> splited;
    int len = words.size(), left = 0;
    for (int i = 0; i < len; i++) {
      if (words[i] == ' ') {
        splited.push_back(words.substr(left, i - left));
        left = i + 1;
      }
    }
    splited.push_back(words.substr(left, len - left));

    return splited;
  }

  bool wordPattern(string pattern, string s) {
    int patternLen = pattern.size();
    vector<string> words = split(s);
    for (string w : words) {
      cout << w << endl;
    }
    if (words.size() != patternLen) {
      cout << "hi";
      return false;
    }

    unordered_map<char, string> pattern_map;
    unordered_map<string, char> words_map;
    for (int i = 0; i < patternLen; i++) {
      char p = pattern[i];
      string w = words[i];
      if (pattern_map.find(p) != pattern_map.end()) {
        if (pattern_map[p] != w) {
          return false;
        }
      } else {
        pattern_map[p] = w;
      }
      if (words_map.find(w) != words_map.end()) {
        if (words_map[w] != p) {
          return false;
        }
      } else {
        words_map[w] = p;
      }
    }

    return true;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  string pattern, words;
  bool res;

  // input
  cout << "\nEnter pattern: ";
  cin >> pattern;
  getchar();
  cout << "Enter words (seperated by space): ";
  getline(cin, words);

  // processing
  res = s.wordPattern(pattern, words);

  // output
  cout << "\n\nResult:\n";
  cout << "The pattern and words are" << (res ? "" : " not") << " match" << endl
       << endl;

  return 0;
}