#include<bits/stdc++.h>
using namespace std;

int N, M;
int adj[10][10];
int adj_new[10][10];
int visited[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<vector<pair<int, int>>> pers;
vector<int> ret;

void init(){
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        adj_new[i][j] = adj[i][j];
    }
}

void per(){
    vector<pair<int, int>> ex;
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        if(adj[i][j]==0){
            ex.push_back({i,j});
        }
    }

    for(int i=0; i<ex.size(); i++)
    for(int j=i+1; j<ex.size(); j++)
    for(int k=j+1; k<ex.size(); k++){
        vector<pair<int, int>> x;
        x.push_back(ex[i]);
        x.push_back(ex[j]);
        x.push_back(ex[k]);
        pers.push_back(x);  
        // cout << "경우의 수: [" << ex[i].first << "][" << ex[i].second << "], [" << ex[j].first << "][" << ex[j].second << "], [" << ex[k].first << "][" << ex[k].second << "]\n";    
    }
    return;
}

void go(int a, int b){
    visited[a][b] = 1;
    queue<pair<int,int>> q;
    q.push({a,b});

    while(q.size()){
        pair<int,int> x = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = x.first + dy[i];
            int nx = x.second + dx[i];

            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            if(adj_new[ny][nx]==0 && visited[ny][nx]==0){
                q.push({ny,nx});
                adj_new[ny][nx] = 2;
                visited[ny][nx] = 1; 
            }
        }
    }
    return;
}

int main(){
    cin >> N >> M;\
    if(N < 3 || M < 3) return 0;
    
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        cin >> adj[i][j];
    }
    
    per();

    for(auto it: pers){
        init();
        fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
        adj_new[it.at(0).first][it.at(0).second] = 1;
        adj_new[it.at(1).first][it.at(1).second] = 1;
        adj_new[it.at(2).first][it.at(2).second] = 1;

        for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(adj_new[i][j]==2 && visited[i][j]==0) go(i, j);
        }
        
        int cnt=0;
        for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(adj_new[i][j]==0) cnt++; 
        }

        ret.push_back(cnt);
    }

    cout << *max_element(ret.begin(), ret.end()) << "\n"; 
    return 0;
}