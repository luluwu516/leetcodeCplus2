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

TreeNode *constructBinaryTree(vector<int> nums);

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    return helper(root, 0, targetSum);
  }

  bool helper(TreeNode *root, int count, const int targetSum) {
    if (!root) {
      return false;
    }
    if (!root->right && !root->left) {
      return root->val + count == targetSum;
    }

    bool left = helper(root->left, root->val + count, targetSum);
    bool right = helper(root->right, root->val + count, targetSum);

    return left || right;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums;
  int num, targetSum;
  bool result;

  // input
  cout << ("Enter numbers, -1 to stop: \n> ");
  cin >> num;
  while (num != -1) {
    nums.push_back(num);
    cout << "> ";
    cin >> num;
  }

  TreeNode *root = constructBinaryTree(nums);

  cout << "\nEnter the target sum: ";
  cin >> targetSum;

  // processing
  result = s.hasPathSum(root, targetSum);

  // output
  cout << "\n\nResult:\n";
  cout << "The root-to-leaf path with the target sum is "
       << (result ? "shown" : "not shown") << endl
       << endl;

  return 0;
}

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
