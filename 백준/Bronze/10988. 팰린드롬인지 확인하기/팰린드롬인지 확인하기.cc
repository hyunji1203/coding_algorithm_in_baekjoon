#include<bits/stdc++.h>
using namespace std;

// 1. 알파벳 소문자 단어 입력 받음
// 2. 거꾸로 읽었을 때 똑같은 지 판별
// 3. 똑같으면 1, 아니면 0 출력

string word;
string reverseWord = "";

int main(){
    cin >> word;

    for(int i=word.size() - 1; i>=0; i--){
        reverseWord = reverseWord + word[i];
    }

    if(word == reverseWord) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}