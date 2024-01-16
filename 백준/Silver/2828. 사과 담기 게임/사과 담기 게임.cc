#include<bits/stdc++.h>
using namespace std;

int N, M, ret=0;
vector<int> apple_locations;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int testcase;
    cin >> testcase;
    
    for(int i=0; i<testcase; i++){
        int location;
        cin >> location;
        apple_locations.push_back(location);
    }

    int l = 1;
    int r = l + M - 1;

    for(int it: apple_locations){
        if(l <= it && it <= r) continue;
        if(it < l){
            ret += l - it;
            l = it;
            r = it + M - 1;
        }else{
            ret += it - r;
            r = it;
            l = r - M + 1;
        }
    }
    cout << ret << "\n";
}