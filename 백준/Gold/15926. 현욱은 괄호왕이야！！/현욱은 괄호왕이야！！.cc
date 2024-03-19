#include<bits/stdc++.h>
using namespace std;

int n, ln, ret = 0;
int d[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    stack<int> stk;
    for(int i=0; i<n; i++){
        char x;
        cin >> x;
        if(!stk.size()) {
            if(x == '(') stk.push(i);
        }else {
            if(x == ')'){
                d[i] = d[stk.top()] = 1;
                stk.pop(); 
            }
            if(x == '(') stk.push(i);
        }
    }
    
    for(int i=0; i<n; i++){
        if(d[i]){
            ln = ln + 1;
            ret = max(ret, ln);
        }else{
            ln = 0;
        }
    }

    cout << ret << "\n";
    return 0;
}