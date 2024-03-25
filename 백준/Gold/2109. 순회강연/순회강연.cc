#include<bits/stdc++.h>
using namespace std;

int n, p, d, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    if(n == 0){
        cout << 0 << "\n";
        return 0;
    }
    for(int i=0; i<n; i++){
        cin >> p >> d;
        v.push_back({d, p});
    }

    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        pq.push({v[i].second});
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }

    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }
    
    cout << ret << "\n";
    return 0;
}