#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class List
{
public:
    Node *head;

    List(vector<int> arr)
    {
        head = nullptr;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            Node *newNode = new Node(arr[i]);
            newNode->next = head;
            head = newNode;
        }
    }

    Node *getMiddle(Node *head) {
        if (head == nullptr) return nullptr;
        Node *slow = head;
        Node *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *merge(Node *list1, Node *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        Node *res = nullptr;
        if (list1->val <= list2->val)
        {
            res = list1;
            res->next = merge(list1->next, list2);
        }
        else
        {
            res = list2;
            res->next = merge(list1, list2->next);
        }
        return res;
    }

    Node *mergeSortList(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        Node *mid = getMiddle(head);
        
        Node *rightpart = mid->next;
        
        mid->next = nullptr;
        
        Node *left = mergeSortList(head);
        Node *right = mergeSortList(rightpart);
        
        Node *sortedList = merge(left, right);
        return sortedList;
    }

    void print(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {8, 25, 6, 1, 4, 3, 0};
    List *L = new List(arr);
    Node *newlist = L->mergeSortList(L->head);
    L->print(newlist);
    return 0;
}
