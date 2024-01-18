#include<bits/stdc++.h>
using namespace std;

string str;
vector<int> smalls = {'a','e','i','o','u'}; 

bool judge1(char a, char b, char c){
    if(find(smalls.begin(), smalls.end(), a) != smalls.end()
    && find(smalls.begin(), smalls.end(), b) != smalls.end()
    && find(smalls.begin(), smalls.end(), c) != smalls.end()){
        return false;
    }
    if(find(smalls.begin(), smalls.end(), a) == smalls.end()
    && find(smalls.begin(), smalls.end(), b) == smalls.end()
    && find(smalls.begin(), smalls.end(), c) == smalls.end()){
        return false;
    }
    return true;
}

bool judge2(char a, char b){
    if(a == b){
        if(a == 'e') return true;
        if(a == 'o') return true;
        return false;
    }
    return true;
}

int main(){
    while(true){
        cin >> str;

        if(str == "end") break;

        bool accept1=true;
        bool accept2=true;
        bool accept3=true;
        int flag = 0;

        for(int i=0; i<str.size(); i++){
            if(find(smalls.begin(), smalls.end(), str[i]) != smalls.end()){
                flag = 1;
            }
            if(str.size() >=3 && i < str.size()-2){
                if(judge1(str[i], str[i+1], str[i+2])){
                }else{
                    accept1 = false;
                }
            }
            if(str.size()>=2 && i < str.size()-1){
                if(judge2(str[i], str[i+1])){
                }else{
                    accept2 = false;
                }
            }
        }

        if(flag != 1) accept3 = false;

        if(accept1 && accept2 && accept3){
            cout << "<" << str << "> is acceptable." << "\n";
        }else{
            cout << "<" << str << "> is not acceptable." << "\n";
        }
    }

    return 0;
}