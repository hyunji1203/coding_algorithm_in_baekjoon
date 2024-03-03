#include<bits/stdc++.h>
using namespace std;

int N, ret=INT_MAX;
string s;
int adj[44];

void go(int here){
    if(here == N+1){
        int sum = 0;
        for(int i=1; i<=(1<<(N-1)); i*=2){
            int cnt = 0;
            for(int j=1; j<=N; j++){
                if(adj[j] & i) cnt++;
            }
            sum += min(cnt, N-cnt);
        }
        ret = min(ret, sum);
        return;
    }
    go(here + 1);
    adj[here] = ~adj[here];
    go(here + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> s;
        int value = 1;
        for(int j=0; j<s.size(); j++){
            if(s[j] == 'T') adj[i] |= value;
            value *= 2;
        }
    }
    go(1);
    cout << ret << "\n";

    return 0;
}