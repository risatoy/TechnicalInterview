//
//  Question1
//  sumOfTwo(a,b,v): You have two integer arrays, a and b, and an integer target value v. Determine
//  whether there is a pair of numbers, where one number is taken from a and the other from b, that can
//  be added together to get a sum of v. Return true if such a pair exists, otherwise return false.
//
//  Created by Risa Toyoshima on 9/17/17.
//  Copyright © 2017 Risa Toyoshima. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool sumOfTwo(vector<int> arr1, vector<int> arr2, int v){
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] + arr2[j] == v)
                return true;
        }
    }
    
    
    return false;
}

int main() {
    vector <int> arr1 = {1, 2, 3, 4, 5, 7};
    vector <int> arr2 = {2, 3, 4, 5, 6};
    int v = 13;
    
    if(sumOfTwo(arr1, arr2, v)) {
        cout << "pair is found!" << endl;
    } else {
        cout << "There is not a pair.." << endl;
    }
    
    return 0;
}
