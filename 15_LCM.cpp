#include <bits/stdc++.h>
using namespace std;

// Function to calculate LCM using GCD
long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    long long N, M;
    
    cout << "N = ";
    cin >> N;
    cout << "M = ";
    cin >> M;

    cout << "LCM: " << lcm(N, M) << endl;

    return 0;
}

/*
N = 4
M = 6
LCM: 12
*/
