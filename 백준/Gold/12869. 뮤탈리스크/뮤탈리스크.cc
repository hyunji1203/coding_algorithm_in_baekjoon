#include<bits/stdc++.h>
using namespace std;

int N;
int scv[3], visited[61][61][61];
int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};

struct X {
    int a, b, c;
};

int go(int a, int b, int c){
    visited[a][b][c] = 1;
    queue<X> q;
    q.push({a,b,c});

    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if(visited[0][0][0]) break;
        for(int i=0; i<6; i++){
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);

            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> scv[i];
    }

    cout << go(scv[0], scv[1], scv[2]) << "\n";
    return 0;
}
