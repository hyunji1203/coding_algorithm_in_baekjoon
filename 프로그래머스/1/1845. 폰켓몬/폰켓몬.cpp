#include<bits/stdc++.h>
using namespace std;

int a[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    memset(a, 0, sizeof(a));
    
    for(int it: nums){
        a[it]++;
    }
    
    for(int i=0; i<200001; i++){
        if(answer >= nums.size()/2) break;
        if(a[i] >= 1){
            answer++;
            a[i]--;
        }
    }
    
    return answer;
}