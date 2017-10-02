//
//  QuestionB
//  Web Crawler: I wrote a crawler that visits web pages, stores a few keywords in a database, and
//  follows links to other web pages. I noticed that my crawler was wasting a lot of time visiting
//  the same pages over and over, so I made a set, "visited", where I'm storing URLs I've already
//  visited. Now the crawler only visits a URL if it hasn't already been visited. Let’s see if we
//  can make this crawler use less memory. See if you can come up with a data structure better than
//  a hash that just stores the entire URL. How can we trim down the amount of space taken up by
//  "visited"? Explain in words and implement your solution.
//
//  Created by Risa Toyoshima on 10/1/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>

using namespace std;

struct node {
    struct node *children[26];
    bool isEndOfWord;
};

node* root = NULL;

node *getNodeWithChildren(){
    struct node *parent = new node;
    parent->isEndOfWord = false;
    
    for (int i=0; i<26; i++)
        parent->children[i] = NULL;
    
    return parent;
}

bool isUrlVisited(string key) {
    node* curr = root;
    bool isVisited = false;
    
    for(int i=0; i<key.length(); i++) {
        int index = key[i]-'a';
        if (!curr->children[index])
            curr->children[index] = getNodeWithChildren();
        
        curr = curr->children[index];
    }
    
    if (curr->isEndOfWord == true){
        isVisited = true;
    }
    curr->isEndOfWord = true;
    
    return isVisited;
}

int main() {
    string keys[] = {"www.google.com", "www.yahoo.com", "www.foo.com" , "www.yahoo.com", "www.foo.com"};
    
    int n = sizeof(keys)/sizeof(keys[0]);
    root = getNodeWithChildren();
    
    for (int i=0; i<n; i++) {
        if (isUrlVisited(keys[i]))
            cout << keys[i] << " is already visited!" << endl;
    }
    
    return 0;
}
