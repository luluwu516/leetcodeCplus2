#include <iostream>

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
  void push_back(ListNode*& list, ListNode*& head) {
    head->next = new ListNode(list->val);
    list = list->next;
    head = head->next;
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr) return nullptr;
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    ListNode head(0);
    ListNode* tailPtr = &head;

    while (list1 && list2) {
      if (list1->val < list2->val)
        push_back(list1, tailPtr);
      else
        push_back(list2, tailPtr);
    }

    while (list1) push_back(list1, tailPtr);

    while (list2) push_back(list2, tailPtr);

    return head.next;
  }
};

void printList(ListNode* head) {
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
}

void getInput(ListNode*& head) {
  ListNode* tempPtr = nullptr;
  int input;

  cout << "Enter the elements of list, -1 to stop: ";
  cin >> input;
  while (input != -1) {
    if (head == nullptr) {
      head = new ListNode(input);
      tempPtr = head;
    } else {
      tempPtr->next = new ListNode(input);
      tempPtr = tempPtr->next;
    }

    cout << "Enter the elements of list, -1 to stop: ";
    cin >> input;
  }
}

int main() {
  // declaration
  Solution s;
  ListNode *list1Head = nullptr, *list2Head = nullptr, *mergedList = nullptr;

  // Input
  cout << "\nList 1\n";
  getInput(list1Head);
  cout << "\nList 2\n";
  getInput(list2Head);

  cout << "\nList 1: [ ";
  printList(list1Head);
  cout << "]\n";
  cout << "List 2: [ ";
  printList(list2Head);
  cout << "]\n";

  // Processing
  cout << "Merging...\n";
  mergedList = s.mergeTwoLists(list1Head, list2Head);

  // Output
  cout << "\nResult:\n";
  cout << "Merged List: [ ";
  printList(mergedList);
  cout << "]\n\n";

  // Free memory
  ListNode* temp;
  while (mergedList != nullptr) {
    temp = mergedList;
    mergedList = mergedList->next;
    delete temp;
  }

  return 0;
}