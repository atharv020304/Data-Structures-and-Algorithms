class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k)
    {
        k -= 1;

        while (temp != nullptr && k > 0)
        {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr)
        {
            // Find kth node from temp
            ListNode* kThNode = getKthNode(temp, k);

            // Less than k nodes remaining
            if (kThNode == nullptr)
            {
                if (prevLast)
                {
                    prevLast->next = temp;
                }
                break;
            }

            // Save beginning of next group
            ListNode* nextNode = kThNode->next;

            // Disconnect current group
            kThNode->next = nullptr;

            // Reverse current group
            ListNode* reversedHead = reverseList(temp);

            // First group
            if (prevLast == nullptr)
            {
                head = reversedHead;
            }
            else
            {
                prevLast->next = reversedHead;
            }

            // After reversal, temp is the last node of this group
            prevLast = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};
