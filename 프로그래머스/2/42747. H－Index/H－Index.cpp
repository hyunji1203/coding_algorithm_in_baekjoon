#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), cmp);
    
    int h = citations[0];
    int idx = 0;
    while(h >= 0 && idx < citations.size()){
        if(idx == citations.size()-1){
            for(int i=citations[idx]; i>=0; i--){
                if(citations[idx] >= h && idx + 1 >= h){
                    answer = h;
                    break;
                }
                h--;
            }    
            break;
        }
        
        for(int i=citations[idx]; i>citations[idx+1]; i--){
            if(citations[idx] >= h && idx + 1 >= h){
                answer = h;
                break;
            }
            h--;
        }    
        idx++;
        if(answer != 0) break;
    }
    
    return answer;
}