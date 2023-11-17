#include <bits/stdc++.h>
using namespace std;

int main() {
    int passengerNumber = 0;
    int getOut, getIn;
    int max = 0;
    
    for(int i=0; i<10; i++) {
        cin >> getOut >> getIn;
        passengerNumber = passengerNumber - getOut;
        passengerNumber = passengerNumber + getIn;

        if(max < passengerNumber) {
            max = passengerNumber;
        }
    }

    cout << max;
}