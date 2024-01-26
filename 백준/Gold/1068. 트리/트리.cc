#include<bits/stdc++.h>
using namespace std;

int N, remove_tree;
vector<int> adj[51];
vector<int> losts;
int ret=0;

void del(int parent){
    if(adj[parent].size()==0) return;
    for(auto it: adj[parent]){
        losts.push_back(it);
        del(it);
    }
    adj[parent].clear();
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        int parent;
        cin >> parent;
        if(parent!=-1){
            adj[parent].push_back(i);
        }
    }

    cin >> remove_tree;
    losts.push_back(remove_tree);
    del(remove_tree);

    for(int i=0; i<N; i++){
        auto index = find(adj[i].begin(), adj[i].end(), remove_tree);
        if(index!=adj[i].end()){
            adj[i].erase(index);
        }
    }

    for(int i=0; i<N; i++){
        if(find(losts.begin(), losts.end(), i) != losts.end()) continue;
        if(adj[i].size()==0) ret++;
    }

    cout << ret << "\n";
    return 0;
}