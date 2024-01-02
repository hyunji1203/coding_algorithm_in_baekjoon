#include<bits/stdc++.h>
using namespace std;

// 1. 각 테스트 케이스 입력 받음
// 2. 각 자리수가 모두 1로만 이루어진 n의 배수 중 가장 작은 자리수 출력

typedef long long ll;

int N;

int main(){
    while (scanf("%d", &N) != EOF){
        int temp = 1, ret = 1;
        while (true){
            if(temp % N == 0){
                cout << ret << "\n";
                break;
            }else{
                temp = (temp * 10) + 1;
                temp %= N;
                ret++;
            }
        } 
    }
    return 0;
}
