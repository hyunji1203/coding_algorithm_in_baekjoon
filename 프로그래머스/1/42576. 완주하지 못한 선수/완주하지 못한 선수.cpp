#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i=0; i<completion.size(); i++) {
        if(mp[completion[i]] == 0) {
            mp[completion[i]] = 1;
        } else {
            mp[completion[i]] = mp[completion[i]] + 1;
        }
    }
    
    for(int i=0; i<participant.size(); i++) {
        if(mp[participant[i]] != 0) {
            if(mp[participant[i]] > 1) {
                mp[participant[i]] = mp[participant[i]] - 1;
            } else if(mp[participant[i]] == 1) {
                mp.erase(participant[i]);
            } 
        } else {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}