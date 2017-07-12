//
//  1.2 CheckPermutation
//  Given two strings, write a method to decide if one is a permutation of the other.
//
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

bool checkPermutation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    else
    {
        map<char, int> myMap;
        map<char, int>::iterator it;
        
        for (int i = 0; i < str1.length(); i++)
            myMap.emplace(str1[i], 0);   //initialize to 0
        
        for (int i = 0; i < str1.length(); i++)
        {
            myMap[str1[i]]++;
            if (myMap.count(str2[i]))
                myMap[str2[i]]--;
            else
                return false;
        }
        
        for (it = myMap.begin(); it != myMap.end(); it++)
        {
            if (it -> second != 0)
                return false;
        }
    }
    
    return true;
}

int main() {
    string str1, str2;
    
    cout << "Type first string: ";
    cin >> str1;
    cout << "Type second string: ";
    cin >> str2;
    
    if (checkPermutation(str1, str2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    
    return 0;
}
