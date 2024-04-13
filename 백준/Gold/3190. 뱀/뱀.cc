#include<bits/stdc++.h>
using namespace std;

int n, k, l, length = 1, ret;
int adj[101][101], visited[101][101];
deque<pair<int, char>> v;
deque<pair<int, int>> dq;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++){
        int co, ro;
        cin >> co >> ro;
        adj[co-1][ro-1] = 1;
    }

    cin >> l;
    for(int i=0; i<l; i++){
        int x;
        char c;
        cin >> x >> c;
        if(c == 'L'){
            v.push_back({x, 3});    
        }else{
            v.push_back({x, 1});
        }
    }

    int time = 1;
    int dir = 1;
    dq.push_back({0, 0});
    visited[0][0] = 1;
    while(true){
        int ny = dq.front().first + dy[dir];
        int nx = dq.front().second + dx[dir];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) break;
        if(visited[ny][nx]) break;
        if(!adj[ny][nx]){  // 사과 없을 때
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }else{
            adj[ny][nx] = 0;
        }

        visited[ny][nx] = 1;
        dq.push_front({ny, nx});
        if(time == v.front().first){
            dir = (dir + v.front().second) % 4;
            v.pop_front();
        }

        time++;
    }

    cout << time << "\n";
    return 0;
}
