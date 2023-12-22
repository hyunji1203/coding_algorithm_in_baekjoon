#include<bits/stdc++.h>
using namespace std;

// 1. 문자열 s를 입력함
// 2. 알파벳 대문자 or 소문자인지 판별한다
//      - 맞다면 13글자씩 민다. 
//      - 아니면 그냥 내비둠
// 3. 암호화한 내용을 출력함

const int ROT = 13;
const int alphabet = 26;
string s;

int main(){
    getline(cin, s);

    for(int i=0; i<s.size(); i++){
        if(65 <= (int)s[i] && (int)s[i] <= 91){
            s[i] = char((s[i] - 'A' + 13) % 26 + 65);
        } else if (97 <= (int)s[i] && (int)s[i] <= 123){
            s[i] = char((s[i] - 'a' + 13) % 26 + 97);
        }
    }

    cout << s << "\n";
    return 0;
}