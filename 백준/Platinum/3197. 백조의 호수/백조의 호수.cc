#include<bits/stdc++.h>
using namespace std;

int R, C, cnt = 0, birdY, birdX;
char adj[1504][1504];
int visited[1504][1504], visited_find[1504][1504];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q, temp, q_swan, temp_swan;

void melt(){
    while(q.size()){
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=R || nx<0 || nx>=C || visited[ny][nx]) continue;
            if(adj[ny][nx] == 'X'){
                visited[ny][nx] = 1;
                adj[ny][nx] = '.';
                temp.push({ny, nx});
            }
        }
    }
    return;
}

bool find(){
    while(q_swan.size()){
        int y, x;
        tie(y, x) = q_swan.front(); q_swan.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=R || nx<0 || nx>=C || visited_find[ny][nx]) continue;
            visited_find[ny][nx] = 1;
            if(adj[ny][nx] == '.'){
                q_swan.push({ny, nx});
            }else if(adj[ny][nx] == 'X'){
                temp_swan.push({ny, nx});
            }else if(adj[ny][nx] == 'L') return true;
        }
    }
    return false;
}

void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   swap(q,empty);
}  

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    // for(int i=0; i<R; i++)
    // for(int j=0; j<C; j++){
    //     scanf(" %c", &adj[i][j]);
    //     if(adj[i][j] == 'L'){
    //         birdY = i;
    //         birdX = j;
    //     }else if(adj[i][j]=='.' || adj[i][j]=='L'){
    //         visited[i][j] = 1;
    //         q.push({i, j});
    //     }
    // }

    for(int i=0; i<R; i++){
        string s;
        cin >> s;
        for(int j=0; j<C; j++){
            adj[i][j] = s[j];
            if(adj[i][j] == 'L'){
                birdY = i;
                birdX = j;
            }
            if(adj[i][j]=='.' || adj[i][j]=='L'){
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    q_swan.push({birdY, birdX});
    visited_find[birdY][birdX] = 1;

    while(true){
        if(find()) break;
        melt();
        q = temp;
        temp = queue<pair<int,int>>();
        q_swan = temp_swan;
        temp_swan = queue<pair<int, int>>();
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}