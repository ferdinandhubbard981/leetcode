#include <bits/stdc++.h>

using namespace std;

bool isPrime(int l) {
    for (int i = 2; i < (l+1) / 2; i++) {
        if (l % i == 0) return false;
    }
    return true;
}
void printPrimes(int n) {
    cout << "primes for " << n << ": ";
    for (int i = 2; i < (n+1)/2; i++) {
        if (isPrime(i) && n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl << endl;
}

int main() {

    int n = 0;
    for (int i = 0; i < 100; i++) {
        n += pow(10, i);
        printPrimes(n);
    }

    return 0;
}