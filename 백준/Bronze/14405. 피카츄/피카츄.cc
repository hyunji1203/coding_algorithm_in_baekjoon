#include<bits/stdc++.h>
using namespace std;

string s;
bool flag = false;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;

    int start = 0;
    while(true){
        if(start == s.size()-1) flag = true;
        if(start + 1 > s.size() - 1) break;
        if("pi" == s.substr(start, 2) || "ka" == s.substr(start, 2)){
            start += 2;
        }else if("chu" == s.substr(start, 3)){
            start += 3;
        }else{
            flag = true;
            break;
        }
    }

    if(flag) cout << "NO" << "\n";
    else cout << "YES" << "\n";

    return 0;
}