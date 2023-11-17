#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int n = 3;
    cin >> t;

    vector<int> results;    

    for(int i=0; i<=t; i++){
        vector<int> testCase;

        for(int j=0; j<10; j++){
            int number;
            cin >> number;
            testCase.push_back(number);
        }
        sort(testCase.begin(), testCase.end());
        results.push_back(testCase[7]);
    }

    for(int i=0; i<t; i++) {
        cout << results[i] << "\n";
    }
}