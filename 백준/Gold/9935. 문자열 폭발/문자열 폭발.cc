#include<bits/stdc++.h>
using namespace std;

string s, explode;
stack<char> stk;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    cin >> explode;
    string temp = "";

    for(int i=0; i<s.size(); i++){
        if(stk.size() >= explode.size()-1 && s[i] == explode[explode.size()-1]){
            temp += s[i];
            for(int j=0; j<explode.size()-1; j++){
                temp += stk.top();
                stk.pop();
            }
            reverse(temp.begin(), temp.end());
            if(temp != explode){
                for(char it: temp){
                    stk.push(it);
                }
            }
            temp = "";
        }else{
            stk.push(s[i]);
        }
    }

    string ret = "";
    if(stk.size()){
        while(stk.size()){
            ret += stk.top(); 
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << "\n";
    }else{
        cout << "FRULA" << "\n";
    }   
}