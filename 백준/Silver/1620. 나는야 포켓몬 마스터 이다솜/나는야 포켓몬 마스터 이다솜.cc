#include<bits/stdc++.h>
using namespace std;

// 1. 포켓몬 수 N과 문제 개수 M을 입력받음
// 2. 포켓몬 수 만큼 포켓몬 이름을 입력받음
// 3. 문제를 입력 받음
//      - 이름으로 주어지면 해당 번호 출력
//      - 번호로 주어지면 이름으로 출력

int N, M;
vector<string> poketmons;
map<string, int> poketmonsMp;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        string poketmon;
        cin >> poketmon;
        poketmons.push_back(poketmon);
        poketmonsMp[poketmon] = i+1;
    }

    for(int i=0; i<M; i++){
        string question;
        cin >> question;
        
        if(atoi(question.c_str()) == 0){
            cout << poketmonsMp[question] << "\n";
        }else {
            cout << poketmons[atoi(question.c_str())-1] << '\n';
        }
    }

    return 0;
}