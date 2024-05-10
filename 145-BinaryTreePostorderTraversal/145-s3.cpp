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
    vector<TreeNode *> st;

    while (root != nullptr || !st.empty()) {
      if (root != nullptr) {
        st.push_back(root);
        root = root->left;
      } else {
        TreeNode *temp = st.back()->right;
        if (temp == nullptr) {
          temp = st.back();
          res.push_back(temp->val);
          st.pop_back();

          while (!st.empty() && temp == st.back()->right) {
            temp = st.back();
            res.push_back(temp->val);
            st.pop_back();
          }
        } else {
          root = temp;
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