#include<bits/stdc++.h>
using namespace std;

int n, arrive, enter, ret;
vector<pair<int, int>> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arrive >> enter;
        v.push_back({arrive, enter});
    }
    sort(v.begin(), v.end());

    int endtime = v[0].first + v[0].second;
    for(int i=1; i<n; i++){
        if(endtime > v[i].first){
            endtime = endtime + v[i].second;
        }else{
            endtime = v[i].first + v[i].second;
        }
    }

    cout << endtime << "\n";

    return 0;
}