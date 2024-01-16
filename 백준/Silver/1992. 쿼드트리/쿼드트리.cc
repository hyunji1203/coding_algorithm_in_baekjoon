#include<bits/stdc++.h>
using namespace std;

int N;
int adj[101][101];
string s;

string quard(int a, int b, int siz){
    if(siz == 1){
        return string(1, adj[a][b]);
    }
    char xx = adj[a][b];
    string ret = "";

    for(int i=a; i<a+siz; i++){
        for(int j=b; j<b+siz; j++){
            if(xx != adj[i][j]){
                ret += '(';
                ret += quard(a, b, siz/2);
                ret += quard(a, b+siz/2, siz/2);
                ret += quard(a+siz/2, b, siz/2);
                ret += quard(a+siz/2, b+siz/2, siz/2);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, adj[a][b]);
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> s; 
        for(int j = 0; j < N; j++){
            adj[i][j] = s[j];
        }
    } 

    cout << quard(0,0,N) << "\n";
    return 0;
}