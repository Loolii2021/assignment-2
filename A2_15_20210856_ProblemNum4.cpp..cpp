// File: ..........cpp
// Purpose: Prime numbers
// Author: mohammed luai
// Section: 15
// ID: 20210856
// TA: mohammed talat
// Date: 5 nov 2023
#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    cout << "Prime numbers between 2 and " << n << " are:" << endl;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number n: ";
    cin >> n;

    if (n < 2) {
        cout << "There are no prime numbers less than 2." << endl;
    } else {
        sieveOfEratosthenes(n);
    }

    return 0;
}
