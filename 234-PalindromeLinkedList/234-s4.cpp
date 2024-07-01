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
    if (!head || !(head->next)) {
      return true;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* reversedSecond = reverseLinkedList(slow->next);
    slow->next = nullptr;
    ListNode* curr = head;

    // reversedSecond will smaller than or equal to the curr
    while (reversedSecond) {
      if (curr->val != reversedSecond->val) {
        return false;
      }
      curr = curr->next;
      reversedSecond = reversedSecond->next;
    }
    return true;
  }

  ListNode* reverseLinkedList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* rHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return rHead;
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