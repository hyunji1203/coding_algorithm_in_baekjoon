#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a[] = {1,2,3,4,5};
    int b[] = {2,1,2,3,2,4,2,5};
    int c[] = {3,3,1,1,2,2,4,4,5,5};
    
    int totala = 0, totalb = 0, totalc = 0;
    for(int i=0; i<answers.size(); i++){
        if(a[i % 5] == answers[i]) totala++;
        if(b[i % 8] == answers[i]) totalb++;
        if(c[i % 10] == answers[i]) totalc++;
    }
    
    int ret = max(totala, totalb);
    ret = max(ret, totalc);
    
    cout << totala << ", " << totalb << ", " << totalc << "\n";
    
    if(ret == totala) answer.push_back(1);
    if(ret == totalb) answer.push_back(2);
    if(ret == totalc) answer.push_back(3);
    
    sort(answer.begin(), answer.end());
    return answer;
}