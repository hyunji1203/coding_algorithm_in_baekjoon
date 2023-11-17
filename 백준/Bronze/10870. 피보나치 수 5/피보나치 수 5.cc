#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> numbers;
    numbers.push_back(0);
    numbers.push_back(1);

    for(int i=2; i<=20; i++) {
        numbers.push_back(numbers[i-1]+numbers[i-2]);
    }

    int n;
    cin >> n;
    cout << numbers[n];
}