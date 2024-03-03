#include<bits/stdc++.h>
using namespace std;

int N, aArea, bArea, aPo, bPo, ret=INT_MAX;
int population[12], visited[12];
vector<int> adj[10];
vector<int> area, other;

void connect(int here){
    visited[here] = 1;
    aArea++;
    for(int there: adj[here]){
        if(visited[there]) continue;
        if(find(area.begin(), area.end(), there) == area.end()) continue;
        connect(there);
    }
}

void connectB(int here){
    visited[here] = 1;
    bArea++;
    for(int there: adj[here]){
        if(visited[there]) continue;
        if(find(other.begin(), other.end(), there) == other.end()) continue;
        connectB(there);
    }
}

void go(){
    for(int mask=0; mask<(1<<N); mask++){
        area = vector<int>();
        other = vector<int>();
        aArea = 0; bArea = 0;
        aPo = 0; bPo = 0;
        
        for(int i=0; i<N; i++){
            if(mask & (1 << i)){
                area.push_back(i);
                aPo += population[i];
            }else{
                other.push_back(i);
                bPo += population[i];
            }
        }
        if(area.size() == 0 || other.size() == 0) continue;
        connect(area[0]); 
        memset(visited, 0, sizeof(visited));
        connectB(other[0]);
        memset(visited, 0, sizeof(visited));
       if(aArea == (int)area.size() && bArea == (int)other.size()){
            int gap = abs(aPo - bPo);
            ret = min(ret, gap);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> population[i];
    }
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int town;
            cin >> town;
            adj[i].push_back(town-1);
        }
    }

    go();

    if(ret == INT_MAX){
        cout << -1 << "\n";
    }else{
        cout << ret << "\n";
    }
    return 0;
}