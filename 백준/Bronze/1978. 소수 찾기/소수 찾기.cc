#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    int count = 0;

    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    for(int number: numbers){
        int divideCount = 0;
        for(int i=1; i<=number; i++){
            if(number % i==0) {
                divideCount++;
            }
        }

        if(divideCount<=2 && number != 1){
            count++;
        }
    }

    cout << count;
}