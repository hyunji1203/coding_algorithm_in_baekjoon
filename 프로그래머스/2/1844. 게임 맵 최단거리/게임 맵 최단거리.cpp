#include<bits/stdc++.h>
using namespace std;

int adj[104][104], visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m;

void go(int a, int b){
    visited[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({a, b});
    
    while(q.size()){
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(adj[ny][nx] == 0 || visited[ny][nx] > 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            adj[i][j] = maps[i][j];
        }
    }
    
    go(0,0);
    
    answer = visited[n-1][m-1];
    if(answer == 0) return -1;
    else return answer;
}