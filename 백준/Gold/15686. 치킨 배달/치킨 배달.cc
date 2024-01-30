#include<bits/stdc++.h>
using namespace std;

int N, M, ret=INT_MAX;
int adj[51][51];
vector<pair<int, int>> homes;
vector<pair<int, int>> chickens;
vector<vector<int>> exist;

void combi(int start, vector<int> v){
    if(v.size() == M){
        exist.push_back(v);
        return;
    }

    for(int i=start+1; i<chickens.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> adj[i][j];
            if(adj[i][j]==1) homes.push_back({i,j});
            if(adj[i][j]==2) chickens.push_back({i,j});
        }
    }
    
    vector<int> v;
    combi(-1, v);

    for(vector<int> it: exist){
        int sum=0;
        for(pair<int, int> home: homes){
            int min_value = INT_MAX;
            for(int idx: it){
                int distance = abs(home.first-chickens[idx].first)+abs(home.second-chickens[idx].second);
                min_value = min(min_value, distance);
            }
            sum += min_value;
        }
        ret = min(ret, sum);
    }

    cout << ret << "\n";
    return 0;
}