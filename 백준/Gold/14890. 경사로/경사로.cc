#include<bits/stdc++.h>
using namespace std;

int N, L, nextY, nextX, ret;
int adj[101][101], visited[101];


int goColumn(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    memset(visited, 0, sizeof(visited));

    while(q.size()){
        int y, x;
        tie(y, x) = q.front(); q.pop();

        if(y >= N-1) return 1;
        if(adj[y][x] == adj[y+1][x]) {
            q.push({y+1, x});
            continue;
        }
        if(abs(adj[y][x]-adj[y+1][x]) > 1) return 0;
        if(adj[y][x]-adj[y+1][x] > 0){
            for(int i=1; i<=L; i++){
                if(visited[y+i]) return 0;
                if(abs(adj[y][x]-adj[y+i][x]) != 1) return 0;
                if(i == L) q.push({y+i, x});
                visited[y+i] = 1;
            }
        }else{
            for(int i=0; i<L; i++){
                if(visited[y-i]) return 0;
                if(abs(adj[y+1][x]-adj[y-i][x]) != 1) return 0;
                if(i == L-1) q.push({y+1, x});
                visited[y-i] = 1;
            }
        }
    }
}

int goRow(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    memset(visited, 0, sizeof(visited));

    while(q.size()){
        int y, x;
        tie(y, x) = q.front(); q.pop();

        if(x >= N-1) return 1;
        if(adj[y][x] == adj[y][x+1]) {
            q.push({y, x+1});
            continue;
        }
        if(abs(adj[y][x]-adj[y][x+1]) > 1) return 0;
        if(adj[y][x]-adj[y][x+1] > 0){
            for(int i=1; i<=L; i++){
                if(visited[x+i]) return 0;
                if(abs(adj[y][x]-adj[y][x+i]) != 1) return 0;
                if(i == L) q.push({y, x+i});
                visited[x+i] = 1;
            }
        }else{
            for(int i=0; i<L; i++){
                if(visited[x-i]) return 0;
                if(abs(adj[y][x+1]-adj[y][x-i]) != 1) return 0;
                if(i == L-1) q.push({y, x+1});
                visited[x-i] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> L;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
        cin >> adj[i][j];
    }

    for(int i=0; i<N; i++){
        ret += goColumn(0, i);
    }
    for(int i=0; i<N; i++){
        ret += goRow(i, 0);
    }

    cout << ret << "\n";
}