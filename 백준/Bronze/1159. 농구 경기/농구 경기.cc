#include<bits/stdc++.h>
using namespace std;

// 1. 선수의 수를 입력 받음
// 2. 선수의 수 만큼 선수의 이름을 입력 받음
// 3. 첫 글자 마다 수를 측정하고 5명보다 적은지 확인
// 4. 5명 이상 이면 해당 알파벳 출력, 5명 이상 알파벳이 없다면 PREDAJA 출력

int playerCount;
vector<string> names;
map<char, int> mp;
vector<char> ret;

void initMp(){
    for(int i=97; i<124; i++){
        mp.insert({(char)i, 0});
    }
}

int main(){
    initMp();

    cin >> playerCount;

    for(int i=0; i<playerCount; i++){
        string name;
        cin >> name;
        names.push_back(name);
    }

    for(auto name: names){
        for(auto it: mp){
            if(it.first == (char)name[0]){
                mp[it.first] = it.second + 1;
            }
        }
    }

    for(auto it: mp){
        if(it.second >= 5){
            ret.push_back(it.first);
        }
    }

    if(ret.size() == 0){
        cout << "PREDAJA" << "\n";
    }else{
        for(char i: ret){
            cout << i;
        }
    }

    return 0;
}