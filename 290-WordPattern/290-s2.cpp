#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> split(string words) {
    vector<string> splited;
    string temp;

    for (char c : words) {
      if (c != ' ') {
        temp += c;
      } else {
        if (!temp.empty()) {
          splited.push_back(temp);
          temp.clear();
        }
      }
    }
    if (!temp.empty()) {
      splited.push_back(temp);
    }

    return splited;
  }

  bool wordPattern(string pattern, string s) {
    vector<string> words;
    words = split(s);
    int pattern_size = pattern.size();

    if (pattern_size != words.size()) {
      return false;
    }

    unordered_map<char, string> pattern_map;
    unordered_map<string, char> words_map;

    for (int i = 0; i < pattern_size; i++) {
      char c = pattern[i];
      string w = words[i];
      if (pattern_map.find(c) != pattern_map.end() && pattern_map[c] != w) {
        return false;
      }
      if (words_map.find(w) != words_map.end() && words_map[w] != c) {
        return false;
      }
      pattern_map[c] = w;
      words_map[w] = c;
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