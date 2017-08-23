//
//  SimpleRecursiveFibonacci
//

/*  Reveiew on Fibonacci
*
*   Fibonacchi Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21 ...
*   fib(0)  ->  0
*   fib(3)  ->  2
*   fib(5)  ->  5
*   fib(6)  ->  8
*
*/

#include <iostream>

using namespace std;

int fib(int n) {
    if (n <= 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
    
}

int main() {
    
    cout << fib(8) << endl;
    
    return 0;
}
