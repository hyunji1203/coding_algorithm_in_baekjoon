#include<bits/stdc++.h>
using namespace std;

int T, N, M, x, y;
vector<int> adj[1004];
int visited[1004];

void go(int here){
    visited[here] = 1;

    for(int there: adj[here]){
        if(visited[there]) continue;
        go(there);
    }
    return;
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for(int testcase=0; testcase < T; testcase++){
        for(int i = 0; i < 1004; i++) adj[i].clear();
        memset(visited, 0, sizeof(visited));

        cin >> N;
        cin >> M;

        for(int i=0; i<M; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int cnt = 0;
        for(int i=1; i<=N; i++){
            if(!visited[i]){
                go(i);
                cnt++;
            }
        }

        if(M == N-1 && cnt == 1) {
            cout << "tree" << "\n";
        }else {
            cout << "graph" << "\n";
        }
    }
    
    return 0;
}