#include<bits/stdc++.h>
using namespace std;

// 1. 단어의 수 N 입력 받음
// 2. N개의 줄마다 단어를 입력 받음
// 3. 좋은 단어인지 확인

int N, ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++){
        string word;
        cin >> word;

        stack<char> st;

        for(char it: word){
            if(st.size() && it == st.top()){
                st.pop();
            }else{
                st.push(it);
            }
        }

        if(st.size() == 0){
            ret++;
        }
    }  

    cout << ret << "\n"; 
}