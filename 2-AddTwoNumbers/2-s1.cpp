#include <iostream>

using namespace std;  // using directive

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = nullptr;
    int n1, n2, sum, carry = 0, prev;
    while (l1 || l2 || carry) {
      prev = carry;
      carry = 0;
      n1 = l1 ? l1->val : 0;
      n2 = l2 ? l2->val : 0;
      sum = n1 + n2 + prev;

      if (sum > 9) {
        sum %= 10;
        carry++;
      }
      ListNode* newNode = new ListNode(sum);

      if (!res) {
        res = newNode;
      } else {
        ListNode* temp = res;
        while (temp->next) {
          temp = temp->next;
        }
        temp->next = newNode;
      }

      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }

    return res;
  }
};

// function prototype
ListNode* insertNode(ListNode*, int);
void printList(ListNode*);

int main() {
  // declaration
  Solution s;
  int input;
  ListNode *l1 = nullptr, *l2 = nullptr;
  ListNode* res;

  // input
  cout << "\nEnter numbers for list 1, -1 to stop: \n> ";
  cin >> input;
  while (input != -1) {
    l1 = insertNode(l1, input);
    cin >> input;
  }

  cout << "\nEnter numbers for list 2, -1 to stop: \n> ";
  cin >> input;
  while (input != -1) {
    l2 = insertNode(l2, input);
    cin >> input;
  }

  // processing
  res = s.addTwoNumbers(l1, l2);

  // output
  cout << "\n\nResult:\n";
  cout << "   ";
  printList(l1);
  cout << " + ";
  printList(l2);
  cout << "----------\n";
  cout << " = ";
  printList(res);
  cout << "\n";

  return 0;
}

ListNode* insertNode(ListNode* list, int data) {
  ListNode* newNode = new ListNode(data);

  if (!list) {
    list = newNode;
  } else {
    ListNode* temp = list;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  return list;
}

void printList(ListNode* list) {
  ListNode* temp;
  temp = list;
  while (temp) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "\n";
}

// sample output
/*

Enter numbers for list 1, -1 to stop:
> 2 4 3 -1

Enter numbers for list 2, -1 to stop:
> 5 6 4 -1


Result:
   2 4 3
 + 5 6 4
----------
 = 7 0 8

*/