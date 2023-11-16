#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> answers;

    for(int i = 1; i<=n;i++) {
        if (n % i == 0) {
            answers.push_back(i);
        }
    }

    cout << answers[k-1];
}