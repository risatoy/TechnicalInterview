//
//  Question2
//  stringReformatting(string): The string s contains dashes that split it into groups of characters. You
//  are given an integer k that represents the number of characters in groups that your output should
//  have. Your goal is to return a new string that breaks s into groups with a length of k by placing
//  dashes at the correct intervals. If necessary, the first group of characters can be shorter than k.
//  It is guaranteed that there are no consecutive dashes in s.
//
//
//  For s = "2-4a0r7-4k" and k = 4, the output should be stringReformatting(s, k) = "24a0-r74k";
//  For s = "2-4a0r7-4k" and k = 3, the output should be stringReformatting(s, k) = "24-a0r-74k".
//
//
//  Created by Risa Toyoshima on 9/17/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>

using namespace std;

string removeChar(string s, char c) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            s.erase(i, 1);
        }
    }
    return s;
}

string stringReformatting(string s, int k) {
    string newS = "";
    int count = 0;
    
    s = removeChar(s, '-');
    
    for (int long i = s.length(); i >= 0; i --) {
         newS.insert(newS.begin(), s[i]);
        if (count == k && i != 0) {
            newS.insert(newS.begin(), '-');
            count = 0;
        }
        count++;
    }
    
    return newS;
}

int main() {
    string s = "2-4a0r7-4k";
    int k = 3;
    
    cout << stringReformatting(s, k) << endl;
    
   
    return 0;
}
