//
//  BST.cpp
//  BinarySearchTree
//
//  Created by Risa Toyoshima on 7/20/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;


//
// Constructor
//

BST::BST() {
    root = NULL;
}


//
// Create a new node
//


BST::node* BST::CreateLeaf(int key) {
    node* n = new node;
    n -> key = key;
    n -> left = NULL;
    n -> right = NULL;
    
    return n;     //so that it will return to the pointer that is pointing to this new node
}


//
//Adding a node
//

void BST::AddLeaf(int key) {    //it always start searching for the place to add at the root

    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node *Ptr) {
    if (root == NULL) {
        root = CreateLeaf(key);
    }
    else if (key < Ptr -> key) {    //go to left side
        if (Ptr -> left != NULL)   //if it is NOT null (has child), move down to left pointer to check again
            AddLeafPrivate(key, Ptr -> left);
        else   //when there is no node, create new node
            Ptr -> left = CreateLeaf(key);
    }
    else if (key > Ptr -> key) {  //go to right side
        if (Ptr -> right != NULL)
            AddLeafPrivate(key, Ptr -> right);
        else
            Ptr -> right = CreateLeaf(key);
    }
    else
        cout << "The key " << key << " has already been added to the tree" << endl;
}


//
//print lowest to greatest key value  [LEFF CURRENT RIGHT]
//

void BST::PrintInOrder() {
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) {
    if (root != NULL) {   //when tree is not empty
        if (Ptr -> left != NULL) {   //if the left pointer of the current node is pointing to something
            PrintInOrderPrivate(Ptr -> left);
        }
        cout << Ptr -> key << " ";
        if (Ptr -> right != NULL) {
            PrintInOrderPrivate(Ptr -> right);
        }
        
    }
    else {
        cout << "The tree is empty" << endl;
    }
}


//
//helper function
//return a pointer to a node that correspond to a key value that we are passing in
//

BST::node* BST::ReturnNode(int key) {
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr) {
    if (Ptr != NULL) {
        if (Ptr -> key == key) {  //found the node that has the key!
            return Ptr;   //return the pointer poiting to the current node
        }
        else {
            if (key < Ptr-> key) {   //if key is smaller, go left
                return ReturnNodePrivate(key, Ptr -> left);
            }
            else {    //if key is greater, go right
                return ReturnNodePrivate(key, Ptr -> right);
            }
        }
    }
    else {
        return NULL;
    }
}


//
//helper function
//As long as root is not poiting to null, return key inside the root
//

int BST::ReturnRootKey() {
    if (root != NULL) {
        return root -> key;
    }
    else {
        return -1000;
    }
}


//
// print out the node that has the key (parent) and it's children nodes
//

void BST::PrintChildren(int key) {
    node* Ptr = ReturnNode(key);   //ReturnNode will return the pointer poitng to the node that has the key, if not found, return NULL
    
    if(Ptr != NULL) {
        cout << "Parent Node = " << Ptr -> key << endl;
        
        Ptr -> left == NULL ?   //Conditional Operator - if true, execute 1st code. if false, execute 2nd code.
        cout << "Left Child = NULL" << endl:
        cout << "Left Child = " << Ptr -> left -> key << endl;
        
        Ptr -> right == NULL ?
        cout << "Right Child = NULL" << endl:
        cout << "Right Child = " << Ptr -> right -> key << endl;
        
    }
    else {
        cout << "Key " << key << " is not in the tree" << endl;
    }
}


//
// helper function
// return the node that has the smallest key
//

int BST::FindSmallest() {
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr) {
    if (root == NULL) {
        cout << "The tree is empty" << endl;
        return -1000;
    }
    else {
        if (Ptr -> left != NULL) {   //only left side always will  be smaller than the parent node
            return FindSmallestPrivate(Ptr -> left);
        }
        else {   //if left poinnter pointing to the null, we made it to the node has smallest key!
            return Ptr -> key;
        }
    }
}


//  /* part 10 */
//
//

void BST::RemoveNode(int key) {
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent) {
    if (root != NULL) { //if check tree has node
        
        if (root -> key == key) {//check if the root node contain the key
            RemoveRootMatch();    //delete the root and reconstruct the tree so that it will retian the bst property
        }
        else {
            if (key < parent -> key && parent -> left != NULL) { //go to left,
                parent -> left -> key == key ?
                RemoveMatch(parent, parent -> left, true) :
                RemoveNodePrivate(key, parent -> left);
            }
            else if (key > parent -> key && parent -> right != NULL) { //go to right,
                parent -> right -> key == key ?
                RemoveMatch(parent, parent -> right, false) :
                RemoveNodePrivate(key, parent -> right);
            }
            else
                cout << "The key " << key << "was not found in the tree." << endl;
        }
        
        
    }
    else {
        cout << "The tree is empty" << endl;
    }
}


//
//  find the smallest in right subtree, replace the root key with the smallest key and delete the node that had the smallest node
//

void BST::RemoveRootMatch() {
    
    if (root != NULL) {
        node* delPtr = root;
        int smallestInRightSubtree;
        
        // Case 0 - 0 children
        if (root -> left == NULL && root -> right == NULL) {
            root = NULL;
            delete delPtr;
        }
        
        // Case 1 - 1 child
        else if (root -> left == NULL && root -> right != NULL) {
            root = root -> right;
            delPtr -> right = NULL;
            delete delPtr;
        }
        else if (root -> left != NULL && root -> right == NULL) {
            root = root -> left;
            delPtr -> left = NULL;
            delete delPtr;
        }
        
        // Case 2 - 2 children
        else {
            smallestInRightSubtree = FindSmallestPrivate(root -> right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root -> key = smallestInRightSubtree;
        }
        
        
    }
    else {
        cout << "Can not remove root. The tree is empty" << endl;
    }
}



//
//
//
void BST::RemoveMatch(node* parent, node* match, bool left) {
    if(root != NULL) {
        node* delPtr;
        int smallestInRightSubtree;
        
        // Case 0 - 0 children
        if (match -> left == NULL && match -> right == NULL) {
            delPtr = match;
            left == true ?
            parent -> left = NULL :   //if left bool is true
            parent -> right = NULL;   //if left bool is false
            delete delPtr;
        }
        
        // Case 1 - 1 Child
        else if (match -> left == NULL && match -> right != NULL) {
            left == true ?
            parent -> left = match -> right :
            parent -> right = match -> right;
            match -> right = NULL;
            delPtr = match;
            delete delPtr;
        }
        else if (match -> left != NULL && match -> right == NULL) {
            left == true ?
            parent -> left = match -> left :
            parent -> right = match -> left;
            match -> left = NULL;
            delPtr = match;
            delete delPtr;
        }
        
        // Case 2 - 2 children
        else {
            smallestInRightSubtree = FindSmallestPrivate(match -> right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match -> key = smallestInRightSubtree;
        }
        
        
    }
    else {
        cout << "Can not remove match. The tree is empty" << endl;
    }
}



//
// deconstroutor
//
BST::~BST() {
    RemoveSubtree(root);
}


//
// remove the node and nodes below
//

void BST::RemoveSubtree(node* Ptr) {
    if (Ptr != NULL) {
        if (Ptr -> left != NULL) {
            RemoveSubtree(Ptr -> left);
        }
        if (Ptr -> right != NULL) {
            RemoveSubtree(Ptr -> right);
        }
        
        delete Ptr;
    }
    else {
        
    }
}




