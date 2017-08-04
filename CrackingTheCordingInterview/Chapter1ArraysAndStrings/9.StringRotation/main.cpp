//
//  9.StringRotation
//  Assume you have a method isSubstring which checks if one word is a substrng of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring.
//  (e.g., "waterbottle" is a rotation of "erbottlewat")
//
//  Created by Risa Toyoshima
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>

using namespace std;

bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    else {
        string tempStr = s1 + s1;
        
        if (tempStr.find(s2) != string::npos)
            return true;
        else
            return false;
    }
}

int main() {
    string s1, s2;
    
    cout << "Type string 1: ";
    cin >> s1;
    cout << "Type string 2: ";
    cin >> s2;
    
    if (isRotation(s1, s2))
        cout << s2 << "is a rotation of " << s1 << endl;
    else
        cout << s2 << " is not a rotation of " << s1 << endl;
    
    return 0;
}
