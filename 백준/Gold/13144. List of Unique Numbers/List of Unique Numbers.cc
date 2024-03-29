#include<bits/stdc++.h>
using namespace std;

long long n, number, s, e, ret = 0;
vector<int> numbers;
long long cnt[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> number;
        numbers.push_back(number);
    }
    
    while(e < n){
        if(!cnt[numbers[e]]){
            cnt[numbers[e]]++;
            e++;
        }else{
            ret += (e-s);
            cnt[numbers[s]]--;
            s++;
        }
    }

    ret += (long long)(e - s) * (e - s + 1) / 2;

    cout << ret << "\n";
    return 0;
}