#include<bits/stdc++.h>
using namespace std;

// 1. 재료 개수 N 입력 받음
// 2. 갑옷을 만드는데 필요한 수 M 입력받음
// 3. 재료 번호를 입력 받음
// 4. 갑옷 만들 수 있는 갯수 세기
// 5. 가능한 수 출력

int N,M,cnt=0;
vector<int> ingredients;


int main(){
    cin >> N;
    cin >> M;

    for(int i=0; i<N; i++){
        int ingredient;
        cin >> ingredient;
        ingredients.push_back(ingredient);
    }

    for(int i=0; i<ingredients.size(); i++){
        for(int j=i+1; j<ingredients.size(); j++){
            if(ingredients[i]+ingredients[j] == M) cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}