/*
*  FibonacchiMemoization
*
*  Find nth fibonacchi number using Memoization
*
*  approach:
*  crate a lookup map
*  whenever we need solution to a subproblem, first look into the lookup map
*  if the value ins there, then return that value
*   otherwise, calculate the value and put the result in the lookup map so that it can be used later
*
*/

#include <iostream>
#include <map>

using namespace std;

map<int, int> lookup;

int fib(int n) {
    if (!lookup.count(n)) {
        if (n <= 1)
            lookup.emplace(n, n);
        else
            lookup.emplace(n, fib(n-1) + fib(n-2));
    }
    
    return lookup[n];
}

int main() {
    
    for (int i = 0; i < 10; i++) {
        cout << fib(i) << ", ";
    }
    cout << endl;
    
    return 0;
}
