#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> numbers;
    cin >> n;
    for(int i=0; i<n; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    int max, min;
    max = *max_element(numbers.begin(), numbers.end());
    min = *min_element(numbers.begin(), numbers.end());

    cout << min << " " << max;
}
