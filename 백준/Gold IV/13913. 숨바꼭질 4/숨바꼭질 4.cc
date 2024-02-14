#include<bits/stdc++.h>
using namespace std;

int N, K;
int visited[100001], route[100001];
vector<int> ret;

void go(int a){
    queue<int> q;
    q.push(a);

    while(q.size()){
        int here = q.front();
        q.pop();
        if(here == K) break;

        for(int next: {here-1, here+1, here*2}){
            if(next >= 0 && next <= 100000){
                if(!visited[next]){
                    visited[next] = visited[here] + 1;
                    q.push(next);
                    route[next] = here;
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
    if(N == K){
        cout << "0\n" << N << "\n";
        return 0;
    }

    visited[N] = 0;
    go(N);

    cout << visited[K] << "\n";
    for(int i=K; i!=N; i = route[i]){
        ret.push_back(i);
    }
    ret.push_back(N);
    reverse(ret.begin(), ret.end());
    for(int it: ret){
        cout << it << " ";
    }

    return 0;
}