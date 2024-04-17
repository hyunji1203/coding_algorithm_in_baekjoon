#include<bits/stdc++.h>
using namespace std;

int t, w;
int plum[1004], dp[1004][2][34];

int go(int idx, int tree, int cnt){
    if(cnt < 0) return INT_MIN;
    if(idx == t) return cnt == 0 ? 0 :INT_MIN;

    if(~dp[idx][tree][cnt]) return dp[idx][tree][cnt];

    dp[idx][tree][cnt] = max(go(idx + 1, tree^1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == plum[idx] - 1);
    return dp[idx][tree][cnt];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof(dp));

    cin >> t >> w;
    for(int i=0; i<t; i++){
        cin >> plum[i];
    }

    cout << max(go(0, 0, w), go(0, 1, w-1)) << "\n";
    return 0;
}