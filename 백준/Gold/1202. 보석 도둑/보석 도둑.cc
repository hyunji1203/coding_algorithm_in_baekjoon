#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, m, v, c, ret;
vector<pair<ll, ll>> jewel;
vector<ll> bags;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> m >> v;
        jewel.push_back({m, v});
    }
    for(int i=0; i<k; i++){
        cin >> c;
        bags.push_back(c);
    }

    sort(jewel.begin(), jewel.end());
    sort(bags.begin(), bags.end());
    priority_queue<ll> pq;

    int j = 0;
    for(int i=0; i<k; i++){
        while(j < n && jewel[j].first <= bags[i]){
            pq.push(jewel[j].second);
            j++;
        }
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";
    return 0;    
}
