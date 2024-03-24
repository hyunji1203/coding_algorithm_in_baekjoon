#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x, y, ret = 0;
vector<pair<ll, ll>> lines;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        lines.push_back({x, y});
    }
    sort(lines.begin(), lines.end());

    int left = lines[0].first;
    int right = lines[0].second;
    for(int i=1; i<n; i++){
        if(lines[i].first > right){
            ret += right - left;
            left = lines[i].first;
            right = lines[i].second;
        }else if(lines[i].first <= right && lines[i].second >= right){
            right = lines[i].second;
        }
    }

    ret += right - left;
    cout << ret << "\n";
    return 0;
}