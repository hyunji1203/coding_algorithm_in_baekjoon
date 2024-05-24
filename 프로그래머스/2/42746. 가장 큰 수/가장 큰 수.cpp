#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp;
    for(int number: numbers){
        string str = to_string(number);
        temp.push_back(str);
    }
    sort(temp.begin(), temp.end(), cmp);
    
    int cnt = 0;
    for(int i=0; i<temp.size(); i++){
        answer += temp[i];
        if(temp[i] == "0") cnt++;
    }
    
    if(cnt == temp.size()){
        return "0";
    }
    return answer;
}