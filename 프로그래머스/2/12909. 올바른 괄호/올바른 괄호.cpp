#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> stk;
    
    for(char it: s){
        if(stk.size()){
            if(it==')'){
                stk.pop();
            }else{
                stk.push(it);
            }
        }else{
            if(it=='(') stk.push(it);
            else {
                answer = false;
                break;
            }
        }
    }
    
    if(stk.size()) answer = false;

    return answer;
}