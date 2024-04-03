#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }
    return helper(nums, 0, nums.size() - 1);
  }

  TreeNode *helper(vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);

    return root;
  }
};

void printBT(const string &prefix, const TreeNode *node, bool isLeft) {
  if (node != nullptr) {
    cout << prefix;
    cout << (isLeft ? "|-- " : "L-- ");
    cout << node->val << endl;
    printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
    printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
  }
}

void printBT(const TreeNode *node) { printBT("", node, false); }

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums;
  int num;

  // input
  cout << ("Enter numbers, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  // processing
  TreeNode *result = s.sortedArrayToBST(nums);

  // output
  cout << "\n\nResult:\n";
  printBT(result);

  return 0;
}