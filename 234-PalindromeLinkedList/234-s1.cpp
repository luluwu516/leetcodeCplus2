#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    stack<int> s;
    ListNode* curr = head;
    while (curr != nullptr) {
      s.push(curr->val);
      curr = curr->next;
    }

    curr = head;
    while (curr != nullptr && curr->val == s.top()) {
      s.pop();
      curr = curr->next;
    }

    return curr == nullptr;

    // vector
    // vector<int> v;
    // ListNode* curr = head;
    // while (curr != nullptr) {
    //   v.push_back(curr->val);
    //   curr = curr->next;
    // }

    // curr = head;
    // while (curr != nullptr && curr->val == v.back()) {
    //   v.pop_back();
    //   curr = curr->next;
    // }

    // return curr == nullptr;
  }
};

// function prototypes
ListNode* constructLinkList(vector<int> nums);
void printLinkList(ListNode* head);

int main() {
  // declaration
  Solution s = Solution();
  int num;
  vector<int> nums;
  struct ListNode* head;
  bool res;

  // input
  cout << "\nEnter numbers to build a Linked List, -1 to stop: \n> ";
  cin >> num;
  while (num != -1) {
    nums.push_back(num);
    cout << "> ";
    cin >> num;
  }
  head = constructLinkList(nums);

  // processing
  res = s.isPalindrome(head);

  // output
  cout << "\nResult:\n";
  cout << "The Linked List, [";
  printLinkList(head);
  cout << "], is" << (res ? "" : " not") << " palindrome" << endl << endl;

  return 0;
}

ListNode* constructLinkList(vector<int> nums) {
  if (nums.empty()) {
    return nullptr;
  }
  ListNode* head = new ListNode(nums[0]);
  ListNode* curr = head;

  for (int i = 1; i < nums.size(); i++) {
    curr->next = new ListNode(nums[i]);
    curr = curr->next;
  }

  return head;
}

void printLinkList(ListNode* head) {
  ListNode* curr = head;
  while (curr->next != nullptr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }
  cout << curr->val;
}