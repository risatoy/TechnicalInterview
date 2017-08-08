//
//  2.ReturnKthToLast
//  Implement an algorithm to find the Kth to last element of a singly linked list.
//
//  Created by Risa Toyoshima
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

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

Node* returnKthToLast(Node* head, int k) {
    Node* p1 = head;
    Node* p2 = head;
    
    int count = 1;
    
    while (p2->next != nullptr) {
        if (count < k) {
            p2 = p2->next;
            count++;
        }
        else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    return p1;
}


int main() {
    Node* head = nullptr;
    int k;
    
    for (int i = 10; i > 0; i--) {
        insert(head, i);
    }
    
    cout << "at which positon to Last do you want?: ";
    cin >> k;
    
    Node* kthNode = returnKthToLast(head, k);
    printList(kthNode);
    
    
    return 0;
}
