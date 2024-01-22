#include<bits/stdc++.h>
using namespace std;

int T;

int main(){
    cin >> T;
    for(int testcase=0; testcase<T; testcase++){
        string str;
        cin >> str;

        stack<char> container;

        for(char it: str){
            if(container.size()){
                if(container.top()=='(' && it == ')'){
                    container.pop();
                }else{
                    container.push(it);
                }
            }else{
                container.push(it);
            }
        }

        if(container.size()){
            cout << "NO" << "\n";
        }else{
            cout << "YES" << "\n";
        }
    }

    return 0;
}