#include<bits/stdc++.h>
using namespace std;

int N, M;
int adj[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> lost;
 
void go(int a, int b){
    visited[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({a,b});

    while(q.size()){
        int x,y;
        tie(y,x) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            if(adj[ny][nx]==0 && visited[ny][nx]==0){
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
            if(adj[ny][nx]==1 && visited[ny][nx]==0){
                lost.push_back({ny,nx});
            }
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

    int cheese;
    int now=100000;
    int time=0;

    while(true){
        now = 0;
        for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(adj[i][j]==1) now++;
        }
        if(now==0) break;
        else cheese = now;
        
        fill(&visited[0][0], &visited[0][0]+101*101, 0);
        for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(adj[i][j]==0) go(i,j);
            break;
        }

        for(auto it: lost){
            adj[it.first][it.second] = 0;
        }

        time++;
    }

    cout << time << "\n";
    cout << cheese << "\n";
    return 0;
}