#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    vector<int> aNumbers;
    vector<int> max;

    cin >> a >> b;
	for(int i=1; i<=a; i++){
        if(a%i==0 ) {
            aNumbers.push_back(i);
        }
    }

    for(int number: aNumbers){
        if(b%number==0) {
            max.push_back(number);
        }
    }
    
    int maxNumber = *max_element(max.begin(), max.end());

    int minNumber = a*b / maxNumber;

    cout << maxNumber << "\n" << minNumber;
}