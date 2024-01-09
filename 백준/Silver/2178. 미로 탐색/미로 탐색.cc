#include<bits/stdc++.h>
using namespace std;

int N, M;
int adj[104][104];
int visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int a, int b){ 
    visited[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({a,b});   

    while(q.size()){
        pair<int, int> here = q.front();
        q.pop();
        int y = here.first;
        int x = here.second;

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            if(adj[ny][nx]==1 && visited[ny][nx]==0){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string a;
        cin >> a;
        for(int j=0; j<M; j++){
            adj[i][j] = (int)a[j]-48;
        }        
    }

    bfs(0,0);

    cout << visited[N-1][M-1] << "\n";
}