#include<bits/stdc++.h>
using namespace std;

int n, ret = 0;
priority_queue<int> pq;

bool che(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i=3; i*i<=n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int sum = 0;
    for(int i=n; i>1; i--){
        if(che(i)){
            pq.push(i);
            sum += i;
            if(sum == n){
                ret++;
                sum -= pq.top();
                pq.pop();
            }else if(sum > n){
                while(sum > n){
                    sum -= pq.top();
                    pq.pop();
                }
            }
        }
    }

    cout << ret << "\n";

    return 0;
}