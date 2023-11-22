#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N;
    vector<int> primeNumbers;

    cin >> M >> N;

    for(int i=M; i <= N; i++) {
        int count = 0;
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                count++;
            }
        }
        if(count == 2) {
            primeNumbers.push_back(i);
        }
    }

    int sum = 0;
    for(int primeNumber: primeNumbers) {
        sum += primeNumber;
    }

    if(primeNumbers.size()==0) {
        cout << -1;
    } else {
        cout << sum << "\n" << primeNumbers[0];
    }
}