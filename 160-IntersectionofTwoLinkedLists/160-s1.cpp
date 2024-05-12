#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* currA = headA;
    ListNode* currB;
    while (currA) {
      currB = headB;
      while (currB) {
        if (currB->val == currA->val) {
          return currB;
        }
        currB = currB->next;
      }
      currA = currA->next;
    }
    return nullptr;
  }
};

// function prototype
void constructIntersectedLinkedList(vector<int>, vector<int>, ListNode*&,
                                    ListNode*&, int, int, int);
ListNode* constructLinkedList(vector<int>);
void printLinkedlist(ListNode* head);

int main() {
  // declaration
  Solution s = Solution();
  ListNode *headA, *headB, *res;
  vector<int> nums1, nums2;
  int num, intersectVal, skipA, skipB;

  // input
  cout
      << ("Enter numbers for list 1, separated by spaces and -1 to stop: \n> ");
  cin >> num;
  while (num != -1) {
    nums1.push_back(num);
    cin >> num;
  }
  cout
      << ("\nEnter numbers for list 2, separated by spaces and -1 to stop: "
          "\n> ");
  cin >> num;
  while (num != -1) {
    nums2.push_back(num);
    cin >> num;
  }

  cout << "\nEnter the intersect value: ";
  cin >> intersectVal;

  cout << "\nEnter the skipA value: ";
  cin >> skipA;
  cout << "Enter the skipB value: ";
  cin >> skipB;

  constructIntersectedLinkedList(nums1, nums2, headA, headB, intersectVal,
                                 skipA, skipB);
  cout << "\nheadA: \n";
  printLinkedlist(headA);
  cout << "headB: \n";
  printLinkedlist(headB);

  // processing
  res = s.getIntersectionNode(headA, headB);

  // output
  cout << "\n\nResult:\n";
  if (res != nullptr) {
    cout << "Intersected at '" << res->val << "'" << endl << endl;
  } else {
    cout << "No intersection" << endl << endl;
  }

  return 0;
}

ListNode* constructLinkedList(vector<int> nums) {
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

void constructIntersectedLinkedList(vector<int> nums1, vector<int> nums2,
                                    ListNode*& headA, ListNode*& headB,
                                    int intersectVal, int skipA, int skipB) {
  headA = constructLinkedList(nums1);
  headB = constructLinkedList(nums2);
  if (intersectVal) {
    ListNode* currA = headA;
    for (int i = 0; i < skipA; i++) {
      currA = currA->next;
    }
    ListNode* currB = headB;
    for (int i = 0; i < skipB; i++) {
      currB = currB->next;
    }
    currB->next = currA->next;
  }
}

void printLinkedlist(ListNode* head) {
  ListNode* curr = head;
  while (curr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}