#include<bits/stdc++.h>
using namespace std;

int n, s, e, ret = 1;
vector<pair<int, int>> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s >> e;
        v.push_back({e, s});
    }

    sort(v.begin(), v.end());

    int starttime = v[0].second;
    int endtime = v[0].first;

    for(int i=1; i<n; i++){
        if(endtime <= v[i].second){
            starttime = v[i].second;
            endtime = v[i].first;
            ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}