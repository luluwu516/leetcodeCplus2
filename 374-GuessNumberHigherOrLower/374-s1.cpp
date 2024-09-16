#include <iostream>

using namespace std;

class Solution {
 public:
  Solution() : pick(0) {}
  void setPick(int num) { pick = num; }

  int guess(int num) {
    if (num == pick) {
      return 0;
    } else if (num > pick) {
      return -1;
    } else {
      return 1;
    }
  }

  int guessNumber(int n) {
    int low = 1, high = n;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int res = guess(mid);
      if (res == 0) {
        return mid;
      } else if (res > 0) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }

 private:
  int pick;
};

int main() {
  // declaration
  Solution s;
  int num, res;
  cout << "\nEnter the pick: ";
  cin >> num;
  s.setPick(num);

  // input
  cout << "Enter a number: ";
  cin >> num;

  // processing
  res = s.guessNumber(num);

  // output
  cout << "\n\nResult: \n";
  cout << "The pick number is " << res << "\n\n";

  return 0;
}