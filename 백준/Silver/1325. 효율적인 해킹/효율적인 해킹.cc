#include<bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<int> adj[10011];
int visited[10011];
vector<int> ret_cnt;
int ret[10011];

void dfs(int here){
    cnt++;
    for(int there: adj[here]){
        if(visited[there]==0){
            visited[there] = 1;
            dfs(there);
        }
    }
    return; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int testcase=0; testcase<M; testcase++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        cnt = 0;
        fill(&visited[0], &visited[0]+10011, 0);
        visited[i] = 1;
        dfs(i);
        ret[i] = cnt;
        ret_cnt.push_back(cnt);
    }

    int max = *max_element(ret_cnt.begin(), ret_cnt.end());
    for(int i=1; i<=N; i++){
        if(ret[i]==max){
            cout << i << " ";
        }
    }
    return 0;
}