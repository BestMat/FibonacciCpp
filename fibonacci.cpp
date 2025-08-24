#include <iostream>
using namespace std;

#define limit 20

// Recursion:
int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else if (n >= 2) {
        int a = fib(n - 1);
        int b = fib(n - 2);
        return a + b;
    } else {
        throw invalid_argument("fib: n >= 0");
        return -1;
    }
}

// Tried non-recursion: [NR = non-recursion]
int fibNR(int n) {
    int x = 1, y = 0, a = 0;

    while (n > 0) {
        a = x;
        x += y;
        y = a;
        --n;
    }

    return y;
}

int main() {
    for (int i = 0; i < limit; ++i) {
        cout << fib(i) << endl;
    }

    for (int i = 0; i < limit; ++i) {
        cout << fibNR(i) << endl;
    } 

    // Prove that every term of fibonacci sequence divisible by 3's index is even:
    for (int i = 0; i < limit; ++i) {
        if (i % 3 == 0) {
            cout << "Index: " << i << " Fibonacci Number: " << fib(i) << " Even: " << (fib(i) % 2 == 0? "true" : "false") << endl;
        }
    }
    return 0;
}
