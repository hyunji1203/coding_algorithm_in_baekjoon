#include<bits/stdc++.h>
using namespace std;

// 1. 아홉 난쟁이키를 입력 받는다.
// 2. 일곱 난쟁이 키 합이 100이 되는 조합을 찾는다.
// 3. 해당 조합을 오름차순 으로 출력한다.

const int n = 9;
vector<int> heights;
vector<vector<int>> combi;
vector<int> ret;

int main(){
    for(int i=0; i<9; i++){
        int height;
        cin >> height;
        heights.push_back(height);
    }

    sort(heights.begin(), heights.end());

    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++){
        if(100 == (accumulate(heights.begin(), heights.end(), 0) - heights[i] - heights[j])){
            for(auto it: heights){
                if(it != heights[i] && it != heights[j]){
                    cout << it << "\n";
                } 
            }
            return 0;
        }
    }
}