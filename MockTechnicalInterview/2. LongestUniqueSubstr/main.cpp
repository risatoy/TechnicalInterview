/*
 *  Given a sting, find the longest substring without repeating characters.
 *
 *  Example:
 *  “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6
 *  “BBBB” the longest substring is “B”, with length 1
 *  “GEEKSFORGEEKS”, with length 7
 *
 *  Approach:
 *  Use map to keep track on the character and the index that it found
 *  Also keep track on maxLength and currLength of substring without repeating characters
 *  Iterate over each characters of the string
 *  if (the character not found in the map)
 *    increment currLength by 1
 *    store the character in map
 *  else (the character found in the map)
 *    currLength is changed by removing the previous repeating character 
 *    and the characters that are before the previous repeating character
 *    if currLength is bigger than maxLength, then update maxLength
 *    update the index of the character in map
 */

#include <iostream>
#include <map>

using namespace std;

int findLongestUniqueSubstr(string str){
    map<char, int> visited;
    
    int maxLength = 1;
    int currLength = 1;
    int prevIndex;
    
    visited.emplace(str[0], 0);
    
    for (int i = 1; i < str.length(); i++) {
        if (!visited.count(str[i])) {
            currLength++;
            visited.emplace(str[i], i);
        }
        else {
            prevIndex = visited[str[i]];
            visited[str[i]] = i;
            if (maxLength < currLength)
                maxLength = currLength;
            if (i - currLength > prevIndex)   //if the previous repeating character is not in the nonrepeating substring
                currLength++;
            else  //if the previous repeating charactrer is in the nonrepeating substring
                currLength = i - prevIndex;
        }
    }
    
    return maxLength;
}

int main() {
    
    string str;
    
    cout << "Input string: ";
    cin >> str;
    
    cout << "The length of the longest non-repeating character substring is "
         << findLongestUniqueSubstr(str) << endl;
    
    return 0;
}
