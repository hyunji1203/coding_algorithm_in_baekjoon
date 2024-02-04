#include<bits/stdc++.h>
using namespace std;

int N, L, R, day=0;
int adj[51][51], visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> united;

void go(int a, int b){
    visited[a][b] = 1;

    for(int i=0; i<4; i++){
        unsigned int ny = a + dy[i];
        unsigned int nx = b + dx[i];

        if(ny>=N || nx>=N) continue;
        int gap = abs(adj[a][b]-adj[ny][nx]);
        if(gap>=L && gap<=R && visited[ny][nx]==0){
            united.push_back({ny,nx});
            go(ny, nx);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> L >> R;

    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
        cin >> adj[i][j];
    }

    while(true){
        bool flag = false;
        for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(visited[i][j]==0){
                united.push_back({i, j});
                go(i, j);
            }

            if(united.size() > 1){
                flag = true;
                int sum = 0;
                for(pair<int, int> it: united){
                    sum += adj[it.first][it.second];
                }
                int result = sum / united.size();
                for(pair<int, int> it: united){
                    adj[it.first][it.second] = result;
                }
            }
            united.clear();
        } 
        if(!flag) break;
        else{
            day++;
            memset(visited, 0, sizeof(visited));
        }
    }

    cout << day << "\n";
    return 0;
}
