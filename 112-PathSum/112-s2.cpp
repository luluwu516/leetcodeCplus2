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
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      return root->val == targetSum;
    }

    bool left = hasPathSum(root->left, targetSum - root->val);
    bool right = hasPathSum(root->right, targetSum - root->val);

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
