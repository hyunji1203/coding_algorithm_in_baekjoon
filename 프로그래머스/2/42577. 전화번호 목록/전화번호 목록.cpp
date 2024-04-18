#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    
    for(string it: phone_book){
        string now = "";
        for(int i=0; i<it.size(); i++){
            now += it[i];
            if(mp[now] == 1) {
                answer = false; 
                break;
            }
        }
        mp[it] = 1;
    }
    
    return answer;
}