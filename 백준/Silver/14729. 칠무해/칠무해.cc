#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
double grade;
priority_queue<double> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> grade;
        if(pq.size() == 7){
            pq.push(grade);
            pq.pop();
        }else pq.push(grade);
    }
    vector<double> v;
    for(int i=0; i<7; i++){
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());

    for(double it: v){
        printf("%.3lf\n",it);
    }

    return 0;
}