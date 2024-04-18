#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stk;
    
    for(int it: arr){
       if(stk.size()){
           if(stk.top() != it){
               stk.push(it);
           }
       }else{
           stk.push(it);
       }
    }

    while(stk.size()){
        answer.push_back(stk.top());
        stk.pop();
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}