#include<bits/stdc++.h>
using namespace std;

int N, M, number, cnt, max_width=INT_MIN, remove_size=INT_MIN;
int adj[51][51], visited[51][51];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int compSize[2504];

int dfs(int a, int b, int cnt){
    if(visited[a][b]) return 0;
    int ret = 1;
    visited[a][b] = cnt;

    for(int i=0; i<4; i++){
        if(!(adj[a][b] & (1<<i))){
            int ny = a + dy[i];
            int nx = b + dx[i];
            ret += dfs(ny,nx, cnt);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
        cin >> adj[i][j];
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                cnt++;
                compSize[cnt] = dfs(i, j, cnt);
                max_width = max(max_width, compSize[cnt]);
            }
        }
    }

    for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
        if(i + 1 < M){
            int a = visited[i+1][j];
            int b = visited[i][j];
            if(a != b){
                remove_size = max(remove_size, compSize[a] + compSize[b]);
            } 
        }
        if(j + 1 < N){
            int a = visited[i][j+1];
            int b = visited[i][j];
            if(a != b){
                remove_size = max(remove_size, compSize[a] + compSize[b]);
            } 
        }
    }

    cout << cnt << "\n" << max_width << "\n" << remove_size << "\n";
    return 0;
}