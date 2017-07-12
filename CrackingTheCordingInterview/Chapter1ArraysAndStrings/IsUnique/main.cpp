//
//  1.1 IsUnique
//  Implement an algorithm to determine if a string has all unique characters.
//
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

bool isUnique(string str)
{
    map<char, bool> myMap;
    
    for (int i = 0; i < str.length(); i++)   //initialize all the keys to false
        myMap.emplace(str[i], false);  //myMap[str[i]] = false;
    
    for (int i = 0; i < str.length(); i++)
    {
        if (myMap[str[i]] == false)
            myMap[str[i]] = true;     //emplace or insert cannnot overwrite value
        else
            return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    string input;
    
    cout << "Input: ";
    cin >> input;
    
    if (isUnique(input))
        cout << "All unique character." << endl;
    else
        cout << "Not unique characters." << endl;
    
    
    return 0;
}
