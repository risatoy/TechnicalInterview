//
//  3.DeleteMiddleNode
//  Implement an algorithm to delete a node in the middle (any node but the first and last node, not necessarily the exact middle) of a singly linked list.
//  Example:
//  Input: a->b->c->d->e->f
//  Result: a->b->d->e->f
//
//  Created by Risa Toyoshima on 8/8/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void insert(Node* &head, char data) {
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

void deleteNodeInMiddle(Node* node) {
    Node* temp;
    
    node->data = node->next->data;
    temp = node->next;
    node->next = node->next->next;
    delete(temp);
    temp = nullptr;
}

int main() {
    Node* head = nullptr;
    
    insert(head, 'f');
    insert(head, 'e');
    insert(head, 'd');
    insert(head, 'c');
    insert(head, 'b');
    insert(head, 'a');
   
    cout << "Before deleting: ";
    printList(head);
    
    deleteNodeInMiddle(head->next->next);
    cout << "After deleted 'c': ";
    printList(head);
    
    
    
    return 0;
}
