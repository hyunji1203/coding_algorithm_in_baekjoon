#include<bits/stdc++.h>
using namespace std;

int M, N, K;
int adj[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt, siz=1;
vector<int> sizes;

void dfs(int a, int b){
    visited[a][b] = 1;

    for(int i=0; i<4; i++){
        int ny = a + dy[i];
        int nx = b + dx[i];

        if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
        if(adj[ny][nx]==0 && visited[ny][nx]==0){
            siz++;
            dfs(ny, nx);
        }
    }
    return;
}

int main(){
    cin >> M >> N >> K;
    for(int i=0; i<K; i++){
        pair<int, int> start;
        pair<int, int> end;
        cin >> start.second >> start.first >> end.second >> end.first;
        for(int j=start.first; j<end.first; j++)
        for(int k=start.second; k<end.second; k++){
            adj[j][k] = 1;
        }
    }

    for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
        if(adj[i][j]==0 && visited[i][j]==0){
            siz=1;
            cnt++;
            dfs(i, j);
            sizes.push_back(siz);
        }
    }

    cout << cnt << "\n";
    sort(sizes.begin(), sizes.end());
    for(int it: sizes){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}