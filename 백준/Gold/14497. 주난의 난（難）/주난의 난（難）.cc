#include<bits/stdc++.h>
using namespace std;

int N, M, joox, jooy, chocox, chocoy, jump = 0;
char adj[304][304];
int visited[304][304];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool flag = true;
queue<pair<int, int>> q;
queue<pair<int, int>> temp;

void go(){
    while(q.size()){
        int x, y;
        tie(y, x) = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue; 
            visited[ny][nx] = jump;
            if(adj[ny][nx] != '0'){
                adj[ny][nx] = '0';
                temp.push({ny, nx});
            }else{
                q.push({ny, nx});
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &jooy, &joox, &chocoy, &chocox);
    jooy--; joox--; chocoy--; chocox--;

    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        scanf(" %c", &adj[i][j]);
    }

    q.push({jooy, joox});
    visited[jooy][joox] = 1;
    while(adj[chocoy][chocox] != '0'){
        jump++;
        go();
        q = temp;
        temp = queue<pair<int,int>>();
    }

    cout << visited[chocoy][chocox] << "\n";
    return 0;
}