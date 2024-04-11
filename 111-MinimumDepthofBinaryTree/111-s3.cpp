#include <iostream>
#include <queue>
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

void printBT(const TreeNode *node);
void printBT(const string &prefix, const TreeNode *node, bool isLeft);
TreeNode *constructBinaryTree(vector<int> nums);

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (right == 0 || left == 0) {
      return max(left, right) + 1;
    }

    // ignore the deeper nodes, but it will modify the tree
    root->left = nullptr;
    root->right = nullptr;

    return min(left, right) + 1;
  }
};

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums;
  int num, result;

  // input
  cout << ("Enter numbers, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  TreeNode *root = constructBinaryTree(nums);
  printBT(root);

  // processing
  result = s.minDepth(root);

  // output
  cout << "\n\nResult:\n";
  cout << "The minimum depth of the tree is " << result << endl << endl;
  printBT(root);

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

void printBT(const TreeNode *node) { printBT("", node, false); }

void printBT(const string &prefix, const TreeNode *node, bool isLeft) {
  if (node != nullptr) {
    cout << prefix;
    cout << (isLeft ? "|-- " : "L-- ");
    cout << node->val << endl;
    printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
    printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
  }
}
