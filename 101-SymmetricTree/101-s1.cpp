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
  bool isSymmetric(TreeNode *root) { return helper(root->left, root->right); }

  bool helper(TreeNode *l, TreeNode *r) {
    if (l == nullptr && r == nullptr) {
      return true;
    }
    if (l == nullptr || r == nullptr) {
      return false;
    }
    if (l->val != r->val) {
      return false;
    }

    return helper(l->left, r->right) && helper(l->right, r->left);
  }
};

TreeNode *constructBinaryTree(vector<int> nums) {
  if (nums.empty()) {
    return nullptr;
  }
  vector<TreeNode *> nodes;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != -1) {
      nodes.push_back(new TreeNode(nums[i]));
    } else {
      nodes.push_back(nullptr);
    }
  }

  int leftIndex = 1, rightIndex = 2;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != -1) {
      if (leftIndex < nums.size()) {
        nodes[i]->left = nodes[leftIndex];
      }
      if (rightIndex < nums.size()) {
        nodes[i]->right = nodes[rightIndex];
      }

      leftIndex += 2;
      rightIndex += 2;
    }
  }
  return nodes[0];
}

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums;
  bool result;
  int num;

  // input
  cout << ("Enter numbers, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  TreeNode *root = constructBinaryTree(nums);

  // processing
  result = s.isSymmetric(root);

  // output
  cout << "\n\nResult:\n";
  if (result) {
    cout << ("This is a symmetric tree.\n\n");
  } else {
    cout << ("This is not a symmetric tree.\n\n");
  }

  return 0;
}