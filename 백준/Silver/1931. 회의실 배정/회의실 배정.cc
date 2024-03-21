#include<bits/stdc++.h>
using namespace std;

int n, from, to, cnt = 1;
vector<pair<int, int>> meetings;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> from >> to;
        meetings.push_back({to, from});
    }

    sort(meetings.begin(), meetings.end());

    int f = meetings[0].second;
    int t = meetings[0].first;

    for(int i=1; i<n; i++){
        if(t > meetings[i].second) continue;
        f = meetings[i].second;
        t = meetings[i].first;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}