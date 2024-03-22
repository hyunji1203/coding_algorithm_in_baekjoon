#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
double grade;
priority_queue<double, vector<double>, greater<double>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> grade;
        pq.push(grade);
    }

    for(int i=0; i<7; i++){
        double temp = pq.top();
        printf("%.3lf\n", temp);
        pq.pop();
    }

    return 0;
}