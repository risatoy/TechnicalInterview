//
//  QuestionA
//  sortByStrings(s,t): Sort the letters in the string s by the order they occur in the string t.
//  You can assume t will not have repetitive characters. For s = "weather" and t = "therapyw",
//  the output should be sortByString(s, t) = "theeraw". For s = "good" and t = "odg", the output
//  should be sortByString(s, t) = "oodg"
//
//
//  Created by Risa Toyoshima on 10/1/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

void sortByStrings(string &s, string &t) {
    map<char, int> myMap;
    
    for (int i = 0; i < t.size(); i++)
    {
        myMap.emplace(t[i], 0);  // initialize to 0
    }
    
    for (int j = 0; j < s.size(); j++)
    {
        if(myMap.count(s[j]))    // if the character exsits in myMap, increment by 1
            myMap[s[j]]++;
    }
    
    
    int k = 0;
    
    for (int i = 0; i < t.size(); i++)
    {
        while (myMap[t[i]] != 0)
        {
            s[k] = t[i];
            myMap[t[i]]--;
            k++;
        }
    }
    
   
}

int main() {
    string s;
    string t;
    
    cout << "Type string s: ";
    cin >> s;
    
    cout << "Type string t: ";
    cin >> t;
    
    
    sortByStrings(s, t);
    
    cout << s << endl;
    
    
    return 0;
}
