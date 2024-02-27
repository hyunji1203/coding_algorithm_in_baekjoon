#include<bits/stdc++.h>
using namespace std;

int R, C, K, cnt = 0;
char adj[6][6];
int visited[6][6];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int a, int b, int c){
    if(a==0 && b==C-1){
        if(c == K) cnt++;
        return;
    }
    for(int i=0; i<4; i++){
        int ny = a + dy[i];
        int nx = b + dx[i];
        if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
        if(visited[ny][nx]) continue;
        if(adj[ny][nx]=='T') continue;
        
        visited[ny][nx] = 1;
        go(ny, nx, c+1);
        visited[ny][nx] = 0;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> K;
    for(int i=0; i<R; i++)
    for(int j=0; j<C; j++){
        cin >> adj[i][j];
    }

    visited[R-1][0] = 1;
    go(R-1, 0, 1);
    cout << cnt << "\n";
    return 0;
}