#include<bits/stdc++.h>
using namespace std;

int N, K;
int visited[100001], cnt[100001]; 

void go(int start){
    queue<int> q;
    q.push(start);

    while(q.size()){
        int here = q.front();
        q.pop();
        
        for(int next: {here-1, here+1, here*2}){
            if(next >= 0 && next <= 100000){
                if(!visited[next]){
                    visited[next] = visited[here] + 1;
                    q.push(next);
                    cnt[next] += cnt[here];
                }else if(visited[next] == visited[here] + 1){
                    cnt[next] += cnt[here];
                }
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    visited[N] = 0;
    cnt[N] = 1;
    
    if(N == K){
        cout << 0 << "\n";
        cout << 1 << "\n";
    }else{
        go(N);
        cout << visited[K] << "\n";
        cout << cnt[K] << "\n";
    }
    return 0;
}