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
  int countNodes(TreeNode *root) {
    int lh = 0;
    int rh = 0;
    TreeNode *curr = root;
    while (curr != NULL) {
      curr = curr->left;
      lh++;
    }
    curr = root;
    while (curr != NULL) {
      curr = curr->right;
      lh++;
    }

    if (lh == rh) {
      return pow(2, lh) - 1;
    } else {
      return 1 + countNodes(root->left) + countNodes(root->right);
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