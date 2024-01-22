#include<bits/stdc++.h>
using namespace std;

int N;
int score1 = 0, score2 = 0;
int second1 = 0, second2 = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int second = 0;
    int current=0;

    for(int testcase=0; testcase<N; testcase++){
        int win;
        string x;
        cin >> win >> x;

        current = atoi(x.substr(0,2).c_str()) * 60 + atoi(x.substr(3,2).c_str());

        if(score1 > score2){
            second1 += current - second;
        }else if(score1 < score2){
            second2 += current - second;
        }
        second = current;

        if(win==1){
            score1++;
        }else{
            score2++;
        }
    }
    if(score1 > score2){
        second1 += 48 * 60 - second;
    }else if(score1 < score2){
        second2 += 48 * 60 - second;
    }


    string sminute1 = "00" + to_string(second1/60);
    string ssecond1 = "00" + to_string(second1%60);
    string sminute2 = "00" + to_string(second2/60);
    string ssecond2 = "00" + to_string(second2%60);

    cout << sminute1.substr(sminute1.size()-2, 2) << ":" << ssecond1.substr(ssecond1.size()-2, 2) << "\n";
    cout << sminute2.substr(sminute2.size()-2, 2) << ":" << ssecond2.substr(ssecond2.size()-2, 2) << "\n";
    return 0;
}