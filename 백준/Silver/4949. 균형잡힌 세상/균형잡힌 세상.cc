#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    
    while(true){
        getline(cin, str);
        if(str==".") break;
        stack<char> stk;

        for(char it: str){
            if(it=='(' || it==')' || it=='[' || it==']'){
                if(stk.size()){
                    if(stk.top()=='(' && it==')'){
                        stk.pop();
                    }else if (stk.top()=='[' && it==']'){
                        stk.pop();
                    }else{
                        stk.push(it);
                    }  
                }else{
                    stk.push(it);
                }
            }
        }

        if(stk.size()){
            cout << "no" << "\n";
        }else{
            cout << "yes" << "\n";
        }
    }    

    return 0;
}