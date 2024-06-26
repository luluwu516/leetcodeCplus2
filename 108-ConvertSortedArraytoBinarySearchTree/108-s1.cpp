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

    int mid = nums.size() / 2;
    vector<int> left, right;
    for (int i = 0; i < mid; i++) {
      left.push_back(nums[i]);
    }

    for (int i = mid + 1; i < nums.size(); i++) {
      right.push_back(nums[i]);
    }

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);

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

void printBT(const TreeNode *node) {
  if (node) {
    printBT("", node, false);
  } else {
    cout << "Tree is empty." << endl;
  }
}

//  -2, 2, 5, 7, 11, 13, 19, 21, 99
// [11,2,19,-2,5,13,21,null,null,null,7,null,null,null,99] or
// [11,5,21,2,7,19,99,-2,null,null,null,13]

// -10, -5, -3, 0, 5, 8, 9
// [0,-5,8,-10,-3,5,9]

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