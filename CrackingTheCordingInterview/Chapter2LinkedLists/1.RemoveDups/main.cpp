//
//  1.RemoveDups
//  Remove duplicates from an unsorted linked list.
//
//  Created by Risa Toyoshima
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
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


void removeDups(Node* head)
{
    map<int, bool> myMap;
    
    Node* prev = head;
    Node* curr = head->next;
    Node* temp;
    
    myMap.emplace(prev->data, true);
    
    while (prev->next != nullptr) {
        if (myMap.count(curr->data)) {
            // delete the node
            temp = curr;
            curr = curr->next;
            prev->next = curr;
            delete(temp);
            temp = nullptr;
        }
        else {
            myMap.emplace(curr->data, true);
            curr = curr->next;
            prev = prev->next;
        }
    }
}




int main() {
    
    int num;
    Node* head = nullptr;
    
    cout << "Type 5 ramdom numbers to create a linked list: " << endl;
    for (int i = 0; i < 5; i++ ) {
        cin >> num;
        insert(head, num);
    }
    
    cout << "Before removing dublicates: ";
    printList(head);
    
    removeDups(head);
    
    cout << "After removing dublicates: ";
    printList(head);
    
    return 0;
}
