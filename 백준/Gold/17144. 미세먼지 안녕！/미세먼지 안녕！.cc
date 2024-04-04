#include<bits/stdc++.h>
using namespace std;

int r, c, t, ret = 0;
int adj[51][51], adj_next[51][51];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> windXY;

void go(int a, int b){
    int sum = 0;
    int spread = adj[a][b] / 5;
    for(int i=0; i<4; i++){
        int ny = a + dy[i];
        int nx = b + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if(adj[ny][nx] == -1) continue;
        adj_next[ny][nx] += spread;
        sum += spread;
    }
    adj_next[a][b] += adj[a][b] - sum;
    return;
}

void windUpper(int a, int b){
    int next = 0;
    int now = 0;
    for(int i=1; i<c; i++){
        next = adj_next[a][i];
        adj_next[a][i] = now;
        now = next;
    }
    for(int i=a-1; i>=0; i--){
        next = adj_next[i][c-1];
        adj_next[i][c-1] = now;
        now = next;
    }
    for(int i=c-2; i>=0; i--){
        next = adj_next[0][i];
        adj_next[0][i] = now;
        now = next;
    }
    for(int i=1; i<a; i++){
        next = adj_next[i][0];
        adj_next[i][0] = now;
        now = next;
    }
}

void windLower(int a, int b){
    int next = 0;
    int now = 0;
    for(int i=1; i<c; i++){
        next = adj_next[a][i];
        adj_next[a][i] = now;
        now = next;
    }
    for(int i=a+1; i<r; i++){
        next = adj_next[i][c-1];
        adj_next[i][c-1] = now;
        now = next;
    }
    for(int i=c-2; i>=0; i--){
        next = adj_next[r-1][i];
        adj_next[r-1][i] = now;
        now = next;
    }
    for(int i=r-2; i>a; i--){
        next = adj_next[i][0];
        adj_next[i][0] = now;
        now = next;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c >> t;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> adj[i][j];
            if(adj[i][j] == -1){
                windXY.push_back({i, j});
            }
        }
    }

    while(t--){
        for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            if(adj[i][j] > 0) go(i, j);
        }

        windUpper(windXY[0].first, windXY[0].second);
        windLower(windXY[1].first, windXY[1].second);

        for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            adj[i][j] = adj_next[i][j];
        }
        adj[windXY[0].first][windXY[0].second] = -1;
        adj[windXY[1].first][windXY[1].second] = -1;
        memset(adj_next, 0, sizeof(adj_next));
    }

    for(int i=0; i<r; i++)
    for(int j=0; j<c; j++){
        if(adj[i][j] > 0) ret += adj[i][j];
    }

    cout << ret << "\n";
    return 0;
}