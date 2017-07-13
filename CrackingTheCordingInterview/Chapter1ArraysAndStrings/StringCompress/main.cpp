//
//  1.6 StringCompress
//  Imprement a method to perform basic string compression using the counts of repeated characters.
//
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string compress(string str){
    string newStr;
    int count = 0;
    
    for(int i = 0; i < str.length(); i++){
        count++;
        
        if(i == str.length() || str[i] != str[i+1]){
            newStr += str[i];
            newStr += to_string(count);
            
            count = 0;
        }
    }
    
    return newStr;
    
}


int main() {
    string input;
    string output;
    
    cout << "Input: ";
    cin >> input;
    
    output = compress(input);
    
    cout << "Output: " << output << endl;
    
    
    return 0;
}
