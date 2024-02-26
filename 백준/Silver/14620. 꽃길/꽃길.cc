#include<bits/stdc++.h>
using namespace std;

int N, ret=INT_MAX;
int adj[20][20], visited[20][20];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int setFlower(int y, int x){
    visited[y][x] = 1;
    int s = adj[y][x];
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        s += adj[ny][nx];
    }
    return s;
}

bool check(int y, int x){
    if(visited[y][x]) return false;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=N) return false;
        if(visited[ny][nx]) return false;
    }
    return true;
}

void withdraw(int y, int x){
    visited[y][x] = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
    return;
}

void go(int cnt, int sum){
    if(cnt == 3){
        ret = min(ret, sum);
        return;
    }
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
        if(check(i, j)){
            go(cnt+1, sum + setFlower(i, j));
            withdraw(i, j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
        cin >> adj[i][j];
    }

    go(0, 0);

    cout << ret << "\n";
    return 0;
}