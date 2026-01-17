class Solution {
  public:
    Node* swapKth(Node* head, int k) {

        if (!head) return head;

        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }

        if (k > count) return head;
        if (2 * k - 1 == count) return head;

        Node* toswapLeft = head;
        Node* LH = nullptr;
        for (int i = 0; i < k - 1; i++) {
            LH = toswapLeft;
            toswapLeft = toswapLeft->next;
        }

        Node* toswapRight = head;
        Node* RH = nullptr;
        for (int i = 0; i < count - k; i++) {
            RH = toswapRight;
            toswapRight = toswapRight->next;
        }

        if (LH) LH->next = toswapRight;
        else head = toswapRight;

        if (RH) RH->next = toswapLeft;
        else head = toswapLeft;

        Node* tempNext = toswapRight->next;
        toswapRight->next = toswapLeft->next;
        toswapLeft->next = tempNext;

        return head;
    }
};
