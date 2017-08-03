//
//  1.3 URLify
//  replace all spaces in a string with '%20'. (assume that the string has sufficient space at the end to hold the additonal characters, and you are given the true length of the string.)
//
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string replaceSpaces(string str, int length)
{
    int countSpace = 0;
    int index;
    
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')      //count the number of space in the string
            countSpace++;
    }
    
    index = (length - 1) + countSpace * 2;      //adding the spaces for %20
    
    
    for (int i = (length - 1); i >= 0 ; i--)
    {
        if (str[i] == ' ')
        {
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            
            index = index - 2;
        }
        else
            str[index] = str[i];
        
        index--;
    }
    
    return str;
}

int main() {
    string input = "I am Risa    ";
    int num = 9;
    
    cout << "Output: " << replaceSpaces(input, num) << endl;
    
    
    
    return 0;
}
