#include<bits/stdc++.h>
using namespace std;

int n, ret;
struct Board{
    int a[24][24];

    void _rotate90(){
        int temp[24][24];
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            temp[i][j] = a[n-j-1][i];
        }
        memcpy(a, temp, sizeof(a));
    }

    void _move(){
        int temp[24][24];
        for(int i=0; i<n; i++){
            int c = -1, flag = 0;
            for(int j=0; j<n; j++){
                if(a[i][j]==0) continue;
                if(flag && a[i][j] == temp[i][c]) {
                    temp[i][c] *= 2;
                    flag = 0;
                }else { 
                    temp[i][++c] = a[i][j];
                    flag = 1;
                }
            }
            for(c++; c<n; c++) temp[i][c] = 0;
        }
        memcpy(a, temp, sizeof(a));
    }

    void get_max(){
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            ret = max(a[i][j], ret);
        }
    }
};

void go(Board bo, int here){
    if(here == 5){
        bo.get_max();
        return;
    }

    for(int i=0; i<4; i++){
        Board newbo = bo;
        newbo._move();
        go(newbo, here + 1);
        bo._rotate90();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    Board bo;

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
        cin >> bo.a[i][j];
    }

    go(bo, 0);
    cout << ret << "\n";

    return 0;
}