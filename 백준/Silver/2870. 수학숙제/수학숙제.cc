#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> ret;

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

string removeZero(string str){
    int flag = 0;
    if(str == "") return "";

    string result = "";
    for(char it: str){
        if(flag == 1){
            result += it;
            continue;
        }
        if((int)it != 48){
            result += it;
            flag = 1;
        }
    }
    if(!result.size()) result = "0";
    return result;
}

int main(){
    cin >> N;
    for(int testcase=0; testcase<N; testcase++){
        string content;
        cin >> content;
        
        string pre="";
        for(char it: content){
            if((int)it >= 97 && (int)it <123){
                if(pre != ""){
                    pre = removeZero(pre);
                    ret.push_back(pre);
                    pre = "";
                }
                continue;
            }else{
                pre += it;
            }
        }
        pre = removeZero(pre);
        if(pre != "") ret.push_back(pre);
    }

    sort(ret.begin(), ret.end(), cmp);

    for(string it: ret){
        cout << it << "\n";
    }
}