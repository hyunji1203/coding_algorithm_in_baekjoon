#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;

    for (int i : num_list) {
        if (n == i) {
            answer = 1;
        }
    }

    return answer;
}