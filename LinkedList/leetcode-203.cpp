class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while (head && head->val == val) {
            ListNode* del = head;
            head = head->next;
            delete del;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
