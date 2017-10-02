//
//  Question3
//  getClosingParen(sentence, openingParenIndex):
//  "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get
//  confusing."
//  Write a function that, given a sentence like the one above, along with the position of an opening
//  parenthesis, finds the corresponding closing parenthesis.
//
//  Example: if the example string above is input with the number 10 (position of the first parenthesis),
//  the output should be 79 (position of the last parenthesis).
//
//  Created by Risa Toyoshima on 9/17/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int getClosingParen(string sentence, int openingParenIndex) {
    stack<char> stackParen;
    
    for (int i = openingParenIndex + 1; i < sentence.length(); i++) {
        if (sentence[i] == '(')
            stackParen.push('(');
        else if (sentence[i] == ')') {
            if (stackParen.empty())
                return i;
            else
                stackParen.pop();
        }
    }
    
    return -1;
    
}

int main() {
    string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
    int openingParenIndex = 57;
    
    cout << "Corresponding Closing parenthesis of the Opening parenthesis at " << openingParenIndex << " is at " <<  getClosingParen(sentence, openingParenIndex) << endl;
}
