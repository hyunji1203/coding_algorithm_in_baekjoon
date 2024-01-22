#include<bits/stdc++.h>
using namespace std;

int N;
string ret;
string six = "666";

int main(){
    cin >> N;

    int sequence = 0;
    for(int i=666; ; i++){
        if(to_string(i).find(six) != string::npos){
            sequence++;
        }
        if(sequence == N){
            ret = to_string(i);
            break;
        }
    }

    cout << ret << "\n";
}