#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }

    void flat(Node* root, Node** head, Node** prev){
        if(!root) return;
        flat(root->left,head,prev);
        if(*head == nullptr){
            *head = root;
        }else{
            (*prev)->right = root;
            root->left = *prev;
        }
        *prev = root;
        flat(root->right,head,prev);
    }

    Node* TreeToDLL(Node* root){
        Node *head = nullptr;
        Node *prev = nullptr;
        flat(root,&head,&prev);
        return head;
    }
};

void printDLL(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    Node* head = root->TreeToDLL(root);
    printDLL(head);
}
