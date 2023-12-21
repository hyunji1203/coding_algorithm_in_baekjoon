#include<bits/stdc++.h>
using namespace std;

// 1. 주차 요금 A,B,C 입력 받음
// 2. 3줄에 걸쳐 차 3대의 각각 도착 & 떠난 시간 입력 받음
// 3. 시간별로 몇대가 주차 되었는지 확인후 돈 계산

int a,b,c;
int times[110];
int price = 0;

void initTimes(){
    fill(&times[0], &times[110], 0);
}

int main(){
    initTimes();
    cin >> a >> b >> c;

    for(int i=0; i<3; i++){
        int start, end;
        cin >> start >> end;

        for(int i= start; i<end; i++){
        times[i] += 1;
        }
    }

    for(int i: times){
        if(i == 1){
            price = price + a;
        } else if (i == 2){
            price = price + (2 * b);
        } else if (i == 3){
            price = price + (3 * c);
        }
    }

    cout << price << "\n";
}