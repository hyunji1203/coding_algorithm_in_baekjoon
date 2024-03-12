#include<bits/stdc++.h>
using namespace std;

int N, M, ret; 
int adj[5][5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        scanf("%1d", &adj[i][j]);
    }

    for(int testcase=0; testcase < (1 << (N*M)); testcase++){
        int sum = 0;
        
        for(int i=0; i<N; i++){
            int cur = 0;
            for(int j=0; j<M; j++){
                int k = i * M + j;
                if((testcase & (1<<k)) == 0){
                    cur = cur * 10 + adj[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for(int j=0; j<M; j++){
            int cur = 0;
            for(int i=0; i<N; i++){
                int k = i * M + j;
                if((testcase & (1 << k)) != 0){
                    cur = cur * 10 + adj[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ret = max(ret, sum);
    }
    
    cout << ret << "\n";
    return 0;
}