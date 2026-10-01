/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // Returns the middle index
    int findMiddle(ListNode* head)
    {
        int size = 0;

        ListNode* temp = head;

        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }

        return size / 2;
    }

    ListNode* reverseLL(ListNode* newHead)
    {
        ListNode* prev = nullptr;
        ListNode* curr = newHead;

        while (curr != nullptr)
        {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode* stHead = head;
        ListNode* eHead = head;

        // Find middle position
        int step = findMiddle(head);

        // Move eHead to the beginning of second half
        for (int i = 0; i < step; i++)
        {
            eHead = eHead->next;
        }

        // Split the list
        ListNode* nxtHead = eHead->next;
        eHead->next = nullptr;

        // Reverse second half
        nxtHead = reverseLL(nxtHead);

        // Merge both halves alternately
        while (nxtHead != nullptr)
        {
            ListNode* temp = stHead->next;

            stHead->next = nxtHead;

            ListNode* eTemp = nxtHead->next;

            nxtHead->next = temp;

            stHead = temp;
            nxtHead = eTemp;
        }
    }
};
