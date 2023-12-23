#include<bits/stdc++.h>
using namespace std;

// 1. 측정 날짜 수와 연속날짜 수를 입력 받음
// 2. 온도를 띄어쓰기로 구분하여 입력받음
// 3. 연속적인 온도 합을 구함
// 4. 그 중 최댓값을 출력함

int dateCount, contiDays;
vector<int> temperatures;
vector<int> sums;
vector<int> ret;

int main(){
    cin >> dateCount >> contiDays;
    for(int i=0; i<dateCount; i++){
        int temperature;
        cin >> temperature;
        temperatures.push_back(temperature);
    }

    sums.push_back(temperatures[0]);
    for(int i=1; i<temperatures.size(); i++){
        sums.push_back(sums[i-1] + temperatures[i]);
    }

    for(int i=sums.size()-1; i>=contiDays-1; i--){
        if(i==contiDays-1){
            ret.push_back(sums[i]);
        }else{
            ret.push_back(sums[i]-sums[i-contiDays]);
        }
    }

    cout << *max_element(ret.begin(), ret.end()) << "\n";
    return 0;
}