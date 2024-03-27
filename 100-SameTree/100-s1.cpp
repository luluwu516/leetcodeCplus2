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
  bool isSameTree(TreeNode *p, TreeNode *q) { return helper(p, q); }

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

    return helper(l->left, r->left) && helper(l->right, r->right);
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
  vector<int> nums1, nums2;
  int num;
  bool isSame;

  // input
  cout << ("The first tree: ");
  cout << ("Enter numbers, -1 to stop: \n> ");
  cin >> num;
  while (num != -1) {
    nums1.push_back(num);
    cout << "> ";
    cin >> num;
  }

  cout << ("\nThe second tree: ");
  cout << ("Enter numbers, -1 to stop: \n> ");
  cin >> num;
  while (num != -1) {
    nums2.push_back(num);
    cout << "> ";
    cin >> num;
  }

  TreeNode *root1 = constructBinaryTree(nums1);
  TreeNode *root2 = constructBinaryTree(nums2);

  // processing
  isSame = s.isSameTree(root1, root2);

  // output
  cout << ("\n\nResult:\n");
  if (isSame) {
    cout << ("They are the same.\n\n");
  } else {
    cout << ("They are not the same.\n\n");
  }

  return 0;
}