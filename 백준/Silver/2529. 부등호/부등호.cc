#include<bits/stdc++.h>
using namespace std;

int k;
long long min_value = LONG_MAX, max_value = LONG_MIN;
int visited[10];
char signs[10];
vector<string> ret;
vector<int> temp;

bool judge(int a, int b, char c){
    if(c == '<') return a < b;
    else return a > b;
}

void go(int idx){
    if(temp.size() == k + 1) {
        string s="";
        for(int it: temp){
            s += to_string(it);
        }
        ret.push_back(s);
        return;
    }

    for(int i=0; i<10; i++){
        if(visited[i]) continue;
        if(!judge(temp[idx], i, signs[idx])) continue;
        visited[i] = 1;
        temp.push_back(i);
        go(idx+1);
        visited[i] = 0;
        temp.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k;
    for(int i=0; i<k; i++){
       cin >> signs[i];
    }

    for(int i=0; i<=9; i++){
        temp.push_back(i);
        visited[i] = 1;
        go(0);
        temp.pop_back();
        visited[i] = 0;
    }

    sort(ret.begin(), ret.end());
    cout << ret[ret.size()-1] << "\n";
    cout << ret[0] << "\n";
    return 0;
}