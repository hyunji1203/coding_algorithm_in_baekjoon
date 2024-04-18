#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(string it: completion){
        if(mp[it] == 0){
            mp[it] = 1;
        }else{
            mp[it] = mp[it] + 1;
        }
    }
    
    for(string it: participant){
        if(mp[it] == 0) {
            answer = it;
            break;
        }else{
            mp[it] = mp[it] - 1;    
        }
    }
    
    return answer;
}