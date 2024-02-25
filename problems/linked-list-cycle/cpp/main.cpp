struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    auto slow = head;
    auto fast = head;
    while (fast != nullptr) {
      slow = slow != nullptr ? slow->next : slow;
      fast = fast->next != nullptr ? fast->next->next : fast->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
