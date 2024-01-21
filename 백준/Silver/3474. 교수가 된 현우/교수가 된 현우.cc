#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
int T, N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int testcase=0; testcase<T; testcase++){
        cin >> N;

        int cnt2 = 0;
        int cnt5 = 0;

        for(int i=2; i<=N; i*=2){
            cnt2 += N / i;
        }
        for(int i=5; i<=N; i*=5){
            cnt5 += N / i;
        }
        cout << min(cnt2, cnt5) << "\n";
    }

    return 0;
}