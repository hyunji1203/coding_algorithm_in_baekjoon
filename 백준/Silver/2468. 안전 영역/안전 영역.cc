#include<bits/stdc++.h>
using namespace std;

int N;
int adj[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ret;

void dfs(int a, int b, int height){
    visited[a][b] = 1;

    for(int i=0; i<4; i++){
        int ny = a + dy[i];
        int nx = b + dx[i];

        if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
        if(adj[ny][nx]>height && visited[ny][nx]==0){
            dfs(ny, nx, height);
        }
    }
    return;
}

int main(){
    int max = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int x;
            cin >> x;
            adj[i][j] = x;
            if(max < x) max = x;
        }
    }

    for(int i=0; i<max; i++){
        int cnt=0;
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(adj[j][k]>i && visited[j][k]==0){
                    dfs(j,k,i);
                    cnt++;
                }
            }
        }
        if(ret < cnt) ret = cnt;
    }

    cout << ret << "\n";

    return 0;
}