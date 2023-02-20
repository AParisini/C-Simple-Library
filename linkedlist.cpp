#include <bits/stdc++.h>
using namespace std;
  
class node {
public:
    int data;
    node* next;

    node(int value){  
        data = value;  
        next = NULL;
    }
};
  
void insertHead(node*& head, int val){
    node* newNode = new node(val);
    newNode->next = head;
    head = newNode;
}
  
void insertMiddle(node* head, int key, int val){
    node* newNode = new node(val);
    if (key == head->data) {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }
  
    node* temp = head;
    while (temp->data != key) {
        temp = temp->next;
        if (temp == NULL) {
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
  
void insertTail(node*& head, int val){
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print(node*& head){
    node* temp = head;
  
    while (temp != NULL) {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){  

    node* head = NULL;
  
    insertHead(head, 1);
    insertHead(head, 2);
    cout << "New Head: ";
    print(head);
    cout << endl;
  
    insertTail(head, 4);
    insertTail(head, 5);
    cout << "New Tail: ";
    print(head);
    cout << endl;
  
    insertMiddle(head, 1, 2);
    insertMiddle(head, 5, 6);
    cout << "After insertion at a given position: ";
    print(head);
    cout << endl;
  
    return 0;
}