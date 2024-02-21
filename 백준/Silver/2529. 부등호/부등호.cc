#include<bits/stdc++.h>
using namespace std;

int k;
long long min_value = LONG_MAX, max_value = LONG_MIN;
int visited[10];
vector<char> signs;
vector<int> temp;

bool judge(int a, int b, char c){
    if(c == '<') return a < b;
    else return a > b;
}

void go(int idx){
    if(temp.size() == signs.size() + 1) {
        string s;
        for(int it: temp){
            s += to_string(it);
        }

        min_value = min(stoll(s), min_value);
        max_value = max(stoll(s), max_value);
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
       char sign;
       cin >> sign;
       signs.push_back(sign); 
    }

    for(int i=0; i<=9; i++){
        temp.push_back(i);
        visited[i] = 1;
        go(0);
        temp.pop_back();
        visited[i] = 0;
    }
    cout << setw(k+1) << setfill('0') << max_value << endl;
    cout << setw(k+1) << setfill('0') << min_value << endl;
    return 0;
}