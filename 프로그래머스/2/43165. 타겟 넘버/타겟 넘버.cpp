#include <string>
#include <vector>

using namespace std;

int ret = 0;

void go(int idx, int sum, int target, vector<int> numbers){
    if(idx == numbers.size()){
        if(target == sum) ret++;
        return;
    }
    go(idx+1, sum + numbers[idx], target, numbers);
    go(idx+1, sum - numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {
    go(0, 0, target, numbers);
    
    return ret;
}