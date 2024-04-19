#include<bits/stdc++.h>
using namespace std;

int ret = INT_MAX;
bool isBig;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    if(sizes[0][0] > sizes[0][1]) isBig = true;
    else isBig = false;
    
    int width = 0;
    int height = 0;
    
    for(vector<int> it: sizes){
        if(it[0] > it[1] == isBig){
            width = max(width, it[0]);
            height = max(height, it[1]);
        }else{
            width = max(width, it[1]);
            height = max(height, it[0]);
        }
    }
    
    answer = width * height;
    return answer;
}