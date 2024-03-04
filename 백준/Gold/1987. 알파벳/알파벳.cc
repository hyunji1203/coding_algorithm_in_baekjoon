#include<bits/stdc++.h>
using namespace std;

int R, C, ret = INT_MIN;
string s;
char adj[21][21];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int a, int b, int num, int cnt){
    ret = max(ret, cnt);
    for(int i=0; i<4; i++){
        int ny = a + dy[i];
        int nx = b + dx[i];
        if(ny<0 || ny >=R || nx<0 || nx>=C) continue;
        int idx = adj[ny][nx] - 'A';
        if(num & (1 << idx)) continue;
        go(ny, nx, num | (1<<idx), cnt+1); 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> s;
        for(int j=0; j<C; j++){
            adj[i][j] = s[j];
        }
    }
    int start = pow(2, adj[0][0] - 'A'); 
    go(0, 0, start, 1);

    cout << ret << "\n";

    return 0;
}