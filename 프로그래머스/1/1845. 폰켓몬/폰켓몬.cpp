#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int solution(vector<int> nums)
{
    int answer = 0;
    
    for(int i=0; i<nums.size(); i++) {
        if (mp.find(nums[i]) == mp.end()) {
            mp.insert({nums[i], 1});
        } else {
            mp[nums[i]] = mp[nums[i]] + 1;
        }
    }
    int aSize = nums.size() / 2;
    if (mp.size() < aSize) {
        answer = mp.size();
    } else if(mp.size() > aSize) {
        answer = aSize;
    } else {
        answer = aSize;
    }
    
    return answer;
}