#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};

ListNode *constructLinkedList(vector<int> nums, int pos) {
  if (nums.empty()) {
    return nullptr;
  }

  ListNode *head = new ListNode(nums[0]);
  ListNode *curr = head;

  for (int i = 1; i < nums.size(); ++i) {
    ListNode *node = new ListNode(nums[i]);
    curr->next = node;
    curr = curr->next;
  }

  if (pos >= 0 && pos < nums.size()) {
    curr->next = head + pos;
  }

  return head;
}

int main() {
  // declaration
  Solution s = Solution();
  vector<int> nums;
  int num, pos;
  ListNode *head = nullptr;
  bool res;

  // input
  cout << "\nEnter numbers, -1 to stop: \n> ";
  cin >> num;
  while (num != -1) {
    nums.push_back(num);
    cout << "> ";
    cin >> num;
  }

  cout << "\nEnter the connected position or -1 to create a linked list "
          "without a cycle: ";
  cin >> pos;

  head = constructLinkedList(nums, pos);
  if (head == nullptr) {
    cout << "Linked list construction failed.\n";
    return 1;
  }

  // processing
  res = s.hasCycle(head);

  // output
  cout << "\nResult:\n";
  cout << "The linked list " << (res ? "has" : "doesn't have")
       << " a cycle\n\n";

  // free memory
  while (head != nullptr) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}