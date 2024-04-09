#include <stdlib.h>

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
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return maxDepth(root) != -1;
  }
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int depthLeft = maxDepth(root->left);
    int depthRight = maxDepth(root->right);

    if (abs(depthLeft - depthRight) > 1) {
      return -1;
    }
    if (depthLeft == -1 || depthRight == -1) {
      return -1;
    }
    return max(depthLeft, depthRight) + 1;
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
  int num;
  bool result;

  // input
  cout << ("Enter numbers, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  TreeNode *root = constructBinaryTree(nums);

  // processing
  result = s.isBalanced(root);

  // output
  cout << "\n\nResult:\n";
  cout << "The tree is " << (result ? "balanced" : "not balanced") << endl
       << endl;

  return 0;
}