#include<bits/stdc++.h>
using namespace std;

int n, number, x, ret;
vector<int> numbers;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> number;
        numbers.push_back(number);
    }
    cin >> x;

    sort(numbers.begin(), numbers.end());

    int left = 0;
    int right =numbers.size()-1;

    while(left < right){
        if(numbers[left] + numbers[right] == x){
            right--;
            ret++;
        }else if(numbers[left] + numbers[right] < x) left++;
        else if(numbers[left] + numbers[right] > x) right--;
    }

    cout << ret << "\n";
    return 0;
}