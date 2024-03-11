#include<bits/stdc++.h>
using namespace std;

int M, x, s = 0;
string command;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M;
    for(int testcase=0; testcase<M; testcase++){
        cin >> command;
        if(command != "all" && command != "empty"){
            cin >> x;
        }

        if(command=="add"){
            s |= (1 << (x-1));
        }else if(command=="remove"){
            if(s & (1 << (x-1))){
                s ^= (1 << (x-1));
            }
        }else if(command=="check"){
            if(s & (1 << (x-1))){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            } 
        }else if(command=="toggle"){
            s ^= (1 << (x-1));
        }else if(command=="all"){
            s = (1 << 20) - 1;
        }else{
            s = 0;
        }
    }

    return 0;
}