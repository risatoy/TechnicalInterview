//
//  main.cpp
//  BinarySearchTree
//
//  Created by Risa Toyoshima on 7/20/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main() {
    
    int TreeKeys[5] = {10, 2, 5, 3, 7};
    int input = 0;
    
    BST myTree;
    
    for (int i = 0; i < 5; i++) {
        myTree.AddLeaf(TreeKeys[i]);
    }
    
    myTree.PrintInOrder();
    
    
    /*
     for (int i = 0; i < 5; i++) {    //check the relation of the node (show its children)
        myTree.PrintChildren(TreeKeys[i]);
        cout << endl;
    }
    */
    
    cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;
    
    cout << "Enter a key velue to delete. Enter -1 to stop the process" << endl;
    while (input != -1) {
        cout << "Delete Node: ";
        cin >> input;
        
        if (input != -1) {
            cout << endl;
            myTree.RemoveNode(input);
            myTree.PrintInOrder();
            cout << endl;
        }
        
    }

    
    
    return 0;
}
