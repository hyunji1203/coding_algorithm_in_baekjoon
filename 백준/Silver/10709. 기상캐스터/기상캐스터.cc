#include<bits/stdc++.h>
using namespace std;

int H, W;
int a[101][101];
int minutes[101][101];

void go(int y, int x){
    int nx = x + 1;

    if(nx >= W) return;
    if(minutes[y][nx] == -1){
        minutes[y][nx] = minutes[y][x] + 1;
        go(y, nx);
    }
    return;
}

int main(){
    cin >> H >> W;
    for(int i=0; i<H; i++){
        string str;
        cin >> str;
        for(int j=0; j<W; j++){
            if(str[j] == 'c'){
                a[i][j] = 1;
                minutes[i][j] = 0;
            }else{
                a[i][j] = 0;
                minutes[i][j] = -1;
            }
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(a[i][j]==1) go(i,j);
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << minutes[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}