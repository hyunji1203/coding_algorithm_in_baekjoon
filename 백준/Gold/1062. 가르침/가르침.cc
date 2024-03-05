#include<bits/stdc++.h>
using namespace std;

int N, K, words[51];
string s;

int count(int bit){
    int cnt = 0;
    for(int word: words){
        if(word && (word & bit) == word) cnt++;
    }
    return cnt;
}

int go(int idx, int k, int bit){
    if(k < 0) return 0;
    if(idx == 26) return count(bit);
    int ret = go(idx+1, k-1, bit | (1 << idx));
    if(idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && idx != 'i'-'a' && idx != 'c'-'a'){
        ret = max(ret, go(idx+1, k, bit));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> s;
        for(char it: s){
            words[i] |= (1 << (it - 'a'));
        }
    }

    cout << go(0, K, 0) << "\n";
    return 0;
}