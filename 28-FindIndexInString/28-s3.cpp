// Solution from LeetCode
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();
    if (n == 0 || m == 0 || m > n) return -1;  // Edge cases

    long long p = 0, t = 0;
    long long h = 1;  // For Rabin-Karp hash

    const long long MOD =
        1000000007;  // Use a large prime number as the modulus

    // Calculate h as 10^(m-1) modulo MOD
    for (int i = 0; i < m - 1; i++) {
      h = (h * 10) % MOD;
    }

    // Calculate the hash value of the needle and the first window of the
    // haystack
    for (int i = 0; i < m; i++) {
      p = (p * 10 + (needle[i] - 'a' + 1)) % MOD;
      t = (t * 10 + (haystack[i] - 'a' + 1)) % MOD;
    }

    // Slide the window over the haystack and compare hash values
    for (int i = 0; i <= n - m; i++) {
      if (p == t) {
        int j;
        for (j = 0; j < m; j++) {
          if (haystack[i + j] != needle[j]) break;
        }
        if (j == m) return i;  // Match found
      }

      // Calculate the hash value for the next window of the haystack
      if (i < n - m) {
        // Remove the contribution of the first character and add the next
        // character
        t = (t - (haystack[i] - 'a' + 1) * h + MOD) % MOD;
        t = (t * 10 + (haystack[i + m] - 'a' + 1)) % MOD;
        // Ensure t is non-negative
        if (t < 0) t += MOD;
      }
    }

    return -1;  // No match found
  }
};

int main() {
  // declaration
  Solution s;
  string haystack, needle;
  int index;

  // input
  cout << "\nEnter the first string: ";
  cin >> haystack;

  cout << "Enter the second string: ";
  cin >> needle;

  // processing
  index = s.strStr(haystack, needle);

  // output
  cout << "\nResult: \n";
  if (index != -1) {
    cout << "The first '" << needle << "' occurs at index " << index << endl;
  } else {
    cout << "'" << needle << "' did not occur in '" << haystack << "'\n\n";
  }

  return 0;
}