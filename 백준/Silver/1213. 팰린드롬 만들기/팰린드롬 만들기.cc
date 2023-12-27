#include<bits/stdc++.h>
using namespace std;

// 1. 영어 이름을 입력 받음
// 2. 가능하면 정답 출력(사전순 앞)
//      - 불가능 하면 I'm Sorry Hansoo 출력
// (홀수가 2개 이상이면 그건 펠린드롬 불가)

string name, ret;
map<char, int> mp;
int cnt;

void initMp(){
    for(int i=65; i<91; i++){
        mp.insert({(char)i, 0});
    }
}

int main(){
    cin >> name;
    initMp();

    for(char x: name){
        for(auto y: mp){
            if(x == y.first){
                mp[x] = y.second + 1;
            }
        }
    }

    int flag = 0;
    for(int i='Z'; i>='A'; i--){
        if(mp[i] % 2 == 1) {
            cnt++;
            if(flag == 0){
                flag = 1;
                ret.push_back(char(i));
                mp[i]--;
            }
        }
    }

    if(cnt >= 2){
        cout << "I'm Sorry Hansoo" << "\n";
    }else{
        for(int i='Z'; i>='A'; i--){
            while(mp[i] > 0){
                ret = char(i) + ret;
                ret += char(i);
                mp[i] = mp[i] - 2;
            }
        }
        
        string answer="";
        for(char it: ret){
            answer += it;
        }
        cout << answer << "\n";
    }

    return 0;
}