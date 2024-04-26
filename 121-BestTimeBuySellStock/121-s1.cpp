#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0, buy = prices[0];
    for (int sell : prices) {
      if (sell > buy) {
        profit = max(profit, sell - buy);
      } else {
        buy = sell;
      }
    }

    return profit;
  }
};

int main() {
  // declaration
  vector<int> prices;
  int input, res;
  Solution s;

  // input
  cout << "Enter the prices, EOF to stop: \n> ";
  while (cin >> input) {
    cout << "> ";
    prices.push_back(input);
  }

  // processing
  res = s.maxProfit(prices);

  // output
  cout << "\n\nResult: " << endl;
  cout << "The maximum profit is: " << res << endl;

  return 0;
}