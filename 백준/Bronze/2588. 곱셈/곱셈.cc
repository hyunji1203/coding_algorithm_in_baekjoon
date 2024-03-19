#include<bits/stdc++.h>
using namespace std;

string a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;


    for(int i=2; i>=0; i--){
        cout << stoi(a.c_str()) * (b[i]-'0') << "\n";
    }
    cout << stoi(a.c_str()) * stoi(b.c_str()) << "\n";
}