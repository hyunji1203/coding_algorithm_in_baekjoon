#include<bits/stdc++.h>
using namespace std;

int N, ret=INT_MIN;
vector<int> numbers;
vector<char> oper;

int cal(char a, int b, int c){
    if(a=='+') return b + c;
    if(a=='-') return b - c;
    if(a=='*') return b * c;
}

void go(int here, int result){
    if(here == numbers.size()-1){
        ret = max(ret, result);
        return; 
    }

    go(here+1, cal(oper[here], result, numbers[here+1]));
    if(here + 2 <= numbers.size() - 1){
        int temp = cal(oper[here+1], numbers[here+1], numbers[here+2]);
        go(here+2, cal(oper[here], result, temp));
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    string s;
    cin >> s;
    for(char it: s){
        if(it == '+' || it == '-' || it == '*'){
            oper.push_back(it);
        }else{
            numbers.push_back(it-'0');
        }
    }

    go(0, numbers[0]);
    cout << ret << "\n";
    return 0;
}