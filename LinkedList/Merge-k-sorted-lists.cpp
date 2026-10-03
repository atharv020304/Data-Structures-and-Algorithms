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
    ListNode* merger(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }

        if(l1->val <= l2->val)
        {
            l1->next = merger(l1->next,l2);
            return l1;
        }else{
            l2->next = merger(l1,l2->next);
            return l2;
        }
    }
    ListNode* caller(vector<ListNode*>& lists, int start, int end)
    {   
        if(start == end)
        {
            return lists[start];
        }
        if(start > end)
        {
            return nullptr;
        }

        int mid = start + (end - start) / 2;

        ListNode* l1 =  caller(lists,start, mid);

        ListNode* l2 = caller(lists,mid+1, end);

        return merger(l1,l2);
        
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return caller(lists,0,n-1);
    }
};
