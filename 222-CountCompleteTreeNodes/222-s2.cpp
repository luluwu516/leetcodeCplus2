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
  void preorder(TreeNode *root, vector<int> &res) {
    if (root == NULL) {
      return;
    }
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
  }

  int countNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }
    vector<int> res;
    preorder(root, res);
    return res.size();
  };
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
  int num, res;

  // input
  cout << ("Enter numbers to construct the tree, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  TreeNode *root = constructBinaryTree(nums);

  // processing
  res = s.countNodes(root);

  // output
  cout << "\n\nResult:\n";
  cout << "There are " << res << " nodes in the tree." << endl << endl;

  return 0;
}