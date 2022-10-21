#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

Node* reverseIteration(Node* &list){
    Node *cur = list;
    Node *prev = NULL;
    while (cur != NULL){
        Node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

Node* reverseRecursion(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *newHead = reverseRecursion(head->next);
    Node *prevHead = head->next;
    prevHead->next = head;
    head->next = NULL;
    return newHead; 
}

void print(Node *&head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    Node *list = new Node(20);
    insertAtHead(list, 30);
    insertAtHead(list, 40);
    insertAtHead(list, 50);
    insertAtHead(list, 60);
    insertAtHead(list, 70);
    // Node *rev = reverseIteration(list);
    // print(rev);
    Node *rev = reverseRecursion(list);
    print(rev);
    return 0;
}