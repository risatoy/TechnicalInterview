//
//  QuestionE
//  decodeString(s): Given an encoded string, return its corresponding decoded string.
//  The encoding rule is: k[encoded_string], where the encoded_string inside the square
//  brackets is repeated exactly k times. Note: k is guaranteed to be a positive integer.
//
//  For s = "4[ab]", the output should be decodeString(s) = "abababab"
//  For s = "2[b3[a]]", the output should be decodeString(s) = "baaabaaa"
//
//
//  Created by Risa Toyoshima on 10/2/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>

using namespace std;

string decodeString(string s) {
    string decodedS;
    string temp;
    
    int num;
    
    for (int i=s.length()-1; i >=0; i--) {
        if (s[i] != ']') {
            if (s[i] == '['){
                i--;
            
                num = s[0] - '0';   //convert char to int
                temp = decodedS;
                for(int j=0; j<num-1; j++) {
                    decodedS += temp;
                }
               
                
            } else {
                temp = s[i];
                decodedS = temp + decodedS;
            }
            
        }
    }
    
    return decodedS;
}

int main() {
    string s = "2[b3[a]]";
    
    cout << decodeString(s) << endl;
    
    return 0;
}
