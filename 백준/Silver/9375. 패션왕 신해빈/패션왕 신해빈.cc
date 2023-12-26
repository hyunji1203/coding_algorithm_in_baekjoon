#include<bits/stdc++.h>
using namespace std;

// 1. 케이스의 수를 입력 받음
// 2. 각 테스트 케이스마다 가진 의상의 수 n을 입력 받음
// 3. 의상의 이름과 의상의 종류가 공백으로 구분되어 입력 받음
// 4. 가능한 모든 조합의 수를 출력

int testcase;
vector<int> ret;

int main(){
    cin >> testcase;

    for(int i=0; i<testcase; i++){
        int clothesCount;
        cin >> clothesCount;

        map<string, int> clothes;

        for(int j=0; j<clothesCount; j++){
            string name, type;
            cin >> name >> type;

            for(auto it: clothes){
                if(it.first == type){
                    clothes[it.first] = it.second + 1;
                }
            }
            if(clothes.find(type) == clothes.end()){
                clothes.insert({type, 1});
            }
        }

        int x = 1;
        for(auto it: clothes){
            x = x * (it.second + 1);
        }
        x = x - 1;
        ret.push_back(x);
    }

    for(int it: ret){
        cout << it << "\n";
    }

    return 0;
}