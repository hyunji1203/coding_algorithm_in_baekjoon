#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int visited[10];

void go(){
    if(v.size() > M) return;
    if(v.size() == M){
        for(int it: v){
            cout << it << " ";
        }
        cout << "\n";
    }

    for(int i=1; i<=N; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        v.push_back(i);
        go();
        visited[i] = 0;
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    go();

    return 0;
}