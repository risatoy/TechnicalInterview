//
//  BST.h
//  BinarySearchTree
//
//  Created by Risa Toyoshima on 7/20/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

class BST {
private:
    
    struct node {
        int key;
        node* left;
        node* right;
    };
    
    node* root;
    
    node* CreateLeaf(int key);
    
    void AddLeafPrivate(int key, node* Ptr);
    void PrintInOrderPrivate(node* Ptr);
    node* ReturnNode(int key); //helper function - return a pointer to a node that correspond to a key value that we are passing in (find the node that has the key value in the tree and return the pointer of the node)
    node* ReturnNodePrivate(int key, node* Ptr);
    int FindSmallestPrivate(node* Ptr);
    void RemoveNodePrivate(int key, node* parent);
    void RemoveRootMatch();
    void RemoveMatch(node* parent, node* match, bool left);
    void RemoveSubtree(node* Ptr);  //it will delete the node Ptr points to and the tree below that 
    
public:
    
    BST();
    ~BST();
    
    void AddLeaf(int key);    //it always start searching for the place to add at the root
    void PrintInOrder();
    int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();   //helper funciont - will use when you delete a node
    void RemoveNode(int key);
    
    
};
