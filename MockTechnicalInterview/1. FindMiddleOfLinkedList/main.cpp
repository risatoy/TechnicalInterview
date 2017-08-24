/*
 *  Find the middle of a given singly linked list
 *
 *  Approach:
 *  Using two pointers (p1 and p2), p1 moves one node at a time and p2 moves two nodes at a time.
 *  Since p2 moves faster, when p2 reacheded to the end node, p1 is always at the middle.
 */

#include <iostream>

using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
};

Node* findMidNode(Node* head) {
    Node* p1 = head;
    Node* p2 = head;
    
    while (p2->next != NULL && p2->next->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}

void insert(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}



int main() {
    Node* head = nullptr;
    

    for (int i = 1; i <= 5; i++) {
        insert(head, i);
    }
    printList(head);
    cout << "Middle Node of LinkedList(Odd): " << findMidNode(head)->data << endl;
    
    cout << endl;
    
    insert(head, 6);
    printList(head);
    cout << "Middle Node of LinkedList(Even): " << findMidNode(head)->data << endl;

    return 0;
}
