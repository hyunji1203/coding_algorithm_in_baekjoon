#include<bits/stdc++.h>
using namespace  std;

int N, mp, mf, ms, mv, min_money=INT_MAX;
int adj[16][5];
// vector<int> ret;
map<int, vector<vector<int>>> rets;

void pick(){
    for(int i=0; i<(1 << N); i++){
        int p = 0, f = 0, s = 0, v = 0, c = 0;
        vector<int> numbers;
        for(int j=0; j<N; j++){
            if(i & (1 << j)){
                p += adj[j][0];
                f += adj[j][1];
                s += adj[j][2];
                v += adj[j][3];
                c += adj[j][4];
                numbers.push_back(j+1);
            }
        }
        if(p>=mp && f>=mf && s>=ms && v>=mv){
            min_money = min(min_money, c);
            if(min_money == c) {
                rets[min_money].push_back(numbers); 
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for(int i=0; i<N; i++){
        cin >> adj[i][0] >> adj[i][1] >> adj[i][2] >> adj[i][3] >> adj[i][4];
    }

    pick();

    if(min_money == INT_MAX){
        cout << -1 << "\n";
    }else{
        cout << min_money << "\n";
        sort(rets[min_money].begin(), rets[min_money].end());
        for(int it: rets[min_money][0]) cout << it << " ";
        cout << "\n";
    }

    return 0;
}