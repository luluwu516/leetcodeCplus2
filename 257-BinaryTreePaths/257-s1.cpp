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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    if (root) {
      helper(root, res, "");
    }
    return res;
  }

  void helper(TreeNode *node, vector<string> &res, string path) {
    path += to_string(node->val);
    if (!node->left && !node->right) {
      res.push_back(path);
    } else {
      path += "->";
      if (node->left) {
        helper(node->left, res, path);
      }
      if (node->right) {
        helper(node->right, res, path);
      }
    }
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    preorderHelper(root, res);
    return res;
  }

  void preorderHelper(TreeNode *root, vector<int> &res) {
    if (root != nullptr) {
      res.push_back(root->val);
      preorderHelper(root->left, res);
      preorderHelper(root->right, res);
    }
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
  vector<int> nums, original;
  vector<string> res;
  TreeNode *root;
  int num;

  // input
  cout << ("Enter numbers, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  root = constructBinaryTree(nums);
  original = s.preorderTraversal(root);

  // processing
  res = s.binaryTreePaths(root);

  // output
  cout << "\n\nOriginal (preorder):\n";
  for (int n : original) {
    cout << n << " ";
  }
  cout << "\nResult:\n";
  for (string string : res) {
    cout << string << " ";
  }
  cout << endl << endl;

  return 0;
}