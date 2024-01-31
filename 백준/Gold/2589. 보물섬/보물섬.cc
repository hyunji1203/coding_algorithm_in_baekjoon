#include<bits/stdc++.h>
using namespace std;

int N, M, min_distance;                                                                                                                                      ;
char adj[51][51];
int visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int a, int b){
    visited[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({a,b});
    
    while(q.size()){
        int y,x;
        tie(y,x) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            if(visited[ny][nx]) continue;
            if(adj[ny][nx]=='W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            min_distance = max(min_distance, visited[ny][nx]);
            q.push({ny,nx});
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        cin >> adj[i][j];
    }

    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        if(adj[i][j]=='L'){
            memset(visited, 0, sizeof(visited));
            bfs(i,j);
        }
    }

    cout << min_distance-1 << "\n";
    return 0;
}