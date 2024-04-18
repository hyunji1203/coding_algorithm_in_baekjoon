#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    for(vector<string> it: clothes){
        if(mp[it[1]] >= 1){
            mp[it[1]] = mp[it[1]] + 1;
        }else{
            mp[it[1]] = 1;
        }
    }
    
    int temp = 1;
    for(pair<string, int> it: mp){
        temp *= (it.second + 1);
        cout << "second" << it.second << "\n";
    }
    answer = temp - 1;
    
    return answer;
}