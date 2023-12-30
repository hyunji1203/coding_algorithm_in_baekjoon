#include<bits/stdc++.h>
using namespace std;

// 1. 자연수 A, 곱할 횟수 B, 나눌 C 입력 받음
// 2. A를 B번 곱한다
// 3. 그 수를 C로 나눴을 때 나머지를 출력

typedef long long ll;
ll A,B,C;

ll fastPow(ll A, ll B){
    if(B==1){ 
        return A % C;
    }
    ll ret = fastPow(A, B / 2);
    ret = (ret * ret) % C;
    if(B % 2){
        ret = (ret * A) % C;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;

    ll ret = fastPow(A, B); 

    cout << ret << "\n";
}