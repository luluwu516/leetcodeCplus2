#include <iostream>

using namespace std;

typedef struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
} ListNode;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* prev = head;
    ListNode* curr = head->next;

    while (curr != nullptr) {
      if (prev->val == curr->val) {
        curr = curr->next;
        prev->next = curr;
      } else {
        curr = curr->next;
        prev = prev->next;
      }
    }

    return head;
  }
};

void printList(ListNode* head) {
  ListNode* curr = head;
  while (curr != nullptr) {
    cout << curr->val << " -> ";
    curr = curr->next;
  }
  cout << "null" << endl;
}

int main() {
  // declaration
  Solution s = Solution();
  int num;
  ListNode* head = nullptr;
  ListNode* curr = head;

  // input
  cout << ("\nEnter numbers, -1 to stop: \n> ");
  cin >> num;
  while (num != -1) {
    if (head == nullptr) {
      head = new ListNode(num);
      curr = head;
    } else {
      curr->next = new ListNode(num);
      curr = curr->next;
    }
    cout << ("> ");
    cin >> num;
  }

  cout << "\nOriginal list: ";
  printList(head);
  ListNode* result = s.deleteDuplicates(head);

  // output
  cout << "\n\nResult:\n";
  printList(head);
  cout << endl;

  return 0;
}
