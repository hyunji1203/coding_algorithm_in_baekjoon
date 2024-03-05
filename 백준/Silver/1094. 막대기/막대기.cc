#include<bits/stdc++.h>
using namespace std;

int X, ret;

void go(int x){
    for(int i=0; i<8; i++){
        if(x & (1 << i)){
            ret++;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> X;

    go(X);
    cout << ret << "\n";
}