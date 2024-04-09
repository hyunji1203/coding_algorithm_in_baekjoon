#include<bits/stdc++.h>
using namespace std;

int n, ret = INT_MAX;
int s[21][21];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
        cin >> s[i][j];
    }

    for(int i=0; i<(1 << n); i++){
        vector<int> st, li;
        int stAbility = 0, liAbility = 0;
        for(int j=0; j<n; j++){
            if(i & (1 << j)) st.push_back(j);
            else li.push_back(j);
        }
        if(st.size() == n/2){
            for(int k=0; k<st.size(); k++)
            for(int l=0; l<st.size(); l++){
                if(k==l) continue;
                stAbility += s[st[k]][st[l]];
            }
            for(int k=0; k<li.size(); k++)
            for(int l=0; l<li.size(); l++){
                if(k==l) continue;
                liAbility += s[li[k]][li[l]];
            }
            int gap = abs(stAbility-liAbility);
            ret = min(gap, ret);
        }
    }

    cout << ret << "\n";
    return 0;
}