struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr) {
      return nullptr;
    }
    const auto size = getListSize(head);
    const auto m = size - n;
    if (m == 0) {
      return head->next;
    }
    auto node = head;
    for (auto i = 0; i < m - 1; ++i) {
      node = node->next;
    }
    if (node != nullptr && node->next != nullptr) {
      node->next = node->next->next;
    }
    return head;
  }

  int getListSize(ListNode *head) {
    auto count = 0;
    auto node = head;
    while (node != nullptr) {
      count += 1;
      node = node->next;
    }
    return count;
  }
};
