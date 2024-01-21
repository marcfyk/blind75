struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) {
      return false;
    }
    auto slow = head;
    auto fast = head->next;
    while (fast != nullptr) {
      if (slow == fast) {
        return true;
      }
      slow = slow != nullptr ? slow->next : slow;
      fast = fast->next != nullptr ? fast->next->next : fast->next;
    }
    return false;
  }
};
