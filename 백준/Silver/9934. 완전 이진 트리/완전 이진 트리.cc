#include<bits/stdc++.h>
using namespace std;

int K;
vector<int> numbers;
vector<int> trees[14];

void search(int start, int end, int level){
    if(start > end) return;
    if(start == end) {
        trees[level].push_back(numbers[start]);
        return;
    }
    int center = (start + end) / 2;
    trees[level].push_back(numbers[center]);
    search(start, center-1, level+1);
    search(center+1, end, level+1);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> K;
    int last = (int)pow(2, K) -1;
    for(int i=0; i<last; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    search(0, numbers.size()-1, 0);

    for(vector<int> it: trees){
        if(!it.size()) continue;
        for(int number: it){
            cout << number << " ";
        }
        cout << "\n";
    }

    return 0;
}