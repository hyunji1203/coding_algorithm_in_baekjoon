#include<bits/stdc++.h>
using namespace std;

int T, n, number;
string p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for(int testcase=0; testcase<T; testcase++){
        cin >> p;
        cin >> n;

        int numbers[n];

        char prefix, split, suffix;
        bool rever = false;

        cin >> prefix;
        for(int i=0; i<n; i++){
            cin >> numbers[i];
            if(i != n-1) cin >> split;
        }
        cin >> suffix;

        int start = 0, last = n - 1, flag = 0;
        for(char it: p){
            if(it == 'R'){
                rever ^= 1;
            }
            if(it == 'D'){
                if(last < start){
                    flag = 1;
                    cout << "error" << "\n";
                    break;
                }else{
                    if(rever) last--;
                    else start++;
                }
            }
        }

        if(flag == 0){
            cout << "[";
            if(rever){
                for(int i=last; i>=start; i--){
                    cout << numbers[i];
                    if(i != start) cout << ",";
                }
            }else{
                for(int i=start; i<=last; i++){
                    cout << numbers[i];
                    if(i != last) cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}