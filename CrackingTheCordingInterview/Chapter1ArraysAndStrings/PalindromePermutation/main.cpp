//
//  1.4 PalindromePermutation
//  Given a string, write a function to check if it is a permutation of a plindrome.
//
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

bool checkPermutationOfPalindrome(string str){
    map<char, int> myMap;
    map<char, int>::iterator it;
    
    str.erase(remove(str.begin(), str.end(), ' '),str.end()); //remove space if exists
    
    for (int i = 0; i < str.length(); i++){
        myMap.emplace(str[i], 0);  //set all to 0
    }
    
    for (int i = 0; i < str.length(); i++){
        myMap[str[i]]++;
    }
    
    int countOdd = 0;
    
    for (it = myMap.begin(); it != myMap.end(); it++){
        if (it -> second % 2 != 0)
            countOdd++;
    }
    
    if(((str.length() % 2 == 0) && countOdd == 0) ||
       ((str.length() % 2 != 0) && countOdd == 1))
        return true;
    else
        return false;
}

int main() {
    string input;
    
    cout << "Input: ";
    getline(cin, input);
    
    if(checkPermutationOfPalindrome(input))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    return 0;
}
