#include<bits/stdc++.h>
using namespace std;

int n, k, ret = 0;
int a[104], visited[104];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<k; i++){
        if(visited[a[i]]) continue;
        if(v.size() == n){
            int lastIndex = 0, pos;

            for(int temp: v){
                int pick = INT_MAX;
                for(int j=i+1; j<k; j++){
                    if(temp == a[j]){
                        pick = j;
                        break;
                    }
                }
                if(lastIndex < pick){
                    lastIndex = pick;
                    pos = temp;
                }

            }
            visited[pos] = 0;
            ret++;
            v.erase(find(v.begin(), v.end(), pos));
        }
        v.push_back(a[i]);
        visited[a[i]] = 1;
    }

    cout << ret << "\n";
    return 0;
}