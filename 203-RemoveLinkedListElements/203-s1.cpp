#include <iostream>
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
  ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr || (head->next == nullptr && head->val == val)) {
      return nullptr;
    }
    head->next = removeElements(head->next, val);
    if (head->val == val) {
      return head->next;
    } else {
      return head;
    }
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
  struct ListNode *head, *res;

  // input
  cout << "\nEnter numbers to build a Linked List, -1 to stop: \n> ";
  cin >> num;
  while (num != -1) {
    nums.push_back(num);
    cout << "> ";
    cin >> num;
  }

  cout << "\nEnter a value to remove: ";
  cin >> num;

  head = constructLinkList(nums);

  // processing and output
  cout << "\nResult:\n";
  cout << "Original: ";
  printLinkList(head);

  res = s.removeElements(head, num);
  cout << "Revised : ";
  printLinkList(res);

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
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}