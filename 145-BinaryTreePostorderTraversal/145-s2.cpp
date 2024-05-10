#include <iostream>
#include <stack>
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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    std::stack<TreeNode *> st;
    TreeNode *node = root, *lastVisit = nullptr;
    while (!st.empty() || node != nullptr) {
      if (node != nullptr) {
        st.push(node);
        node = node->left;
      } else {
        TreeNode *top = st.top();
        if (top->right != nullptr && lastVisit != top->right) {
          node = top->right;
        } else {
          res.push_back(top->val);
          st.pop();
          lastVisit = top;
        }
      }
    }
    return res;
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
  vector<int> nums, result;
  int num;

  // input
  cout << ("Enter numbers, EOF to stop: \n> ");
  while (cin >> num) {
    nums.push_back(num);
    cout << "> ";
  }

  TreeNode *root = constructBinaryTree(nums);

  // processing
  result = s.postorderTraversal(root);

  // output
  cout << "\n\nPreorder Traversal Result:\n";
  for (int n : result) {
    cout << n << " ";
  }
  cout << endl << endl;

  return 0;
}