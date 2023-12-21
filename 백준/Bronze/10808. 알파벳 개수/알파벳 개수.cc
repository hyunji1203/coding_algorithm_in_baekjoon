#include<bits/stdc++.h>
using namespace std;

// 1. 단어 s 입력
// 2. 각각의 단어가 어떤 소문자인지 판별 후 해당 소문자 값 상승
// 3. 소문자 순서대로 공백으로 구분해서 개수 출력

string s;
map<char, int> words;

void initPair(){
    for(int i=97; i<123; i++){
        words.insert({(char)i, 0});
    }
}

int main(){
    cin >> s;
    initPair();

    for(int i=0; i<s.size(); i++){
        words[s[i]] = words[s[i]] + 1;
    }

    for(auto it: words){
        cout << it.second << ' ';
    }

    return 0;
}