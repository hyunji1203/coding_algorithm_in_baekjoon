#include <bits/stdc++.h>
using namespace std;

vector<int> bubble(vector<int> numbers){
	for(int i=0; i<numbers.size(); i++){
		for(int j=0; j<numbers.size() - 1 - i; j++){
			int temp;
			if(numbers[j] > numbers[j + 1]){
				temp = numbers[j + 1];
				numbers[j + 1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
	return numbers;
}

int main() {
    int n;
    cin >> n;
    
	vector<int> numbers;
	for(int i=0; i<n; i++){
		int number;
		cin >> number;
		numbers.push_back(number);
	}

	numbers = bubble(numbers);

	for(int it: numbers){
		cout << it << " ";
	}
	cout << "\n";
	return 0;
}