#include<bits/stdc++.h>
using namespace std;

int T;
int N, M, K;
int adj[51][51];
bool visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> ret;

void dfs(int a, int b){
    visited[a][b] = 1;

    for(int i=0; i<4; i++){
        int ny = a + dy[i];
        int nx = b + dx[i];
        
        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(adj[ny][nx]==1 && visited[ny][nx]==0){
            dfs(ny, nx);
        }
    }
    return;
}

int main(){
    cin >> T;
    for(int testcase=0; testcase<T; testcase++){
        fill(&adj[0][0], &adj[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            int a, b;
            cin >> a >> b;
            adj[b][a] = 1;
        }

        int cnt=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(adj[i][j]==1 && visited[i][j]==0){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        ret.push_back(cnt);
    }   

    for(int it: ret){
        cout << it << "\n";
    }
    return 0;
}
