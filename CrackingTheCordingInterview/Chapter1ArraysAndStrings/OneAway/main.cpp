//
//  1.5 OneAway
//  There are three types of edits that can be performend on strings: insert a character, remove a character, or replace a character. Given two strings, write a fuction to check if they are one edit (or zero edit) away.
//
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <cstdlib>  //abs
#include <map>


using namespace std;

bool OneAway(string longStr, string shortStr);

bool OneOrZeroEditsAway(string str1, string str2){
    if (abs((int)(str1.length() - str2.length())) > 1){
        return false;
    }
    else{
        if (str1.length() > str2.length() || str1.length() == str2.length()){
            if(OneAway(str1, str2))
                return true;
        }
        else if (str2.length() > str1.length()){
            if(OneAway(str2, str1))
                return true;
        }
    }
    
    return false;
}

bool OneAway(string longStr, string shortStr){
    map<char, int> myMap;
    map<char, int>::iterator it;
    
    for (int i = 0; i < longStr.length(); i++){   // initialize to 0
        myMap.emplace(longStr[i], 0);
    }
    
    for (int i = 0; i < longStr.length(); i++){
        if (myMap.count(longStr[i]))    //check longStr
            myMap[longStr[i]]++;
        if (myMap.count(shortStr[i]))      //check shortStr
            myMap[shortStr[i]]--;
    }
    
    int countNotZero = 0;
    
    for (it = myMap.begin(); it != myMap.end(); it++){
        if (it -> second != 0)
            countNotZero++;
        if (countNotZero > 1 || it -> second > 1)
            return false;
    }
    
    return true;
}

int main(){
    string str1, str2;
    
    cout << "Type first string: ";
    cin >> str1;
    
    cout << "Type second string: ";
    cin >> str2;
    
    if (OneOrZeroEditsAway(str1, str2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    
    return 0;
}



