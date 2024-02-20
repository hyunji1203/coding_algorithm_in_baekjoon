#include<bits/stdc++.h>
using namespace std;

int R, C, max_value;
char adj[24][24];
int visited[30];
int dy[] = {-1, 0 ,1, 0}, dx[] = {0, 1, 0, -1};

void go(int a, int b, int cnt){
    max_value = max(max_value, cnt);

    for(int i=0; i<4; i++){
        int ny = a + dy[i];
        int nx = b + dx[i];

        if(ny<0 || ny>=R || nx<0 || nx >= C) continue;
        if(visited[adj[ny][nx] - 'A']) continue;
        visited[adj[ny][nx] - 'A'] = 1;
        go(ny, nx, cnt+1);
        visited[adj[ny][nx] - 'A'] = 0;
    }   
    return;
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> adj[i][j];
        }
    }

    visited[adj[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << max_value << "\n";

    return 0;
}