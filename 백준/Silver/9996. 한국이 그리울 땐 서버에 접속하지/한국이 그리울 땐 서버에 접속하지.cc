#include<bits/stdc++.h>
using namespace std;

// 1. 파일의 개수 N을 입력 받음
// 2. 패턴을 입력 받음
// 3. 파일 이름을 입력 받음
// 4. 패턴에 맞는지 확인
//      - 맞다면 DA 출력
//      - 다르다면 NE 출력

int fileCount;
string pattern;
vector<string> ret;

int main(){
    cin >> fileCount;

    cin >> pattern;
    int index = pattern.find("*");
    string prefix = pattern.substr(0, index);
    string suffix = pattern.substr(index+1);

    for(int i=0; i<fileCount; i++){
        string filename;
        cin >> filename;

        int flag = 0;

        for(int j=0; j<prefix.size(); j++){
            if(prefix[j] != filename[j]){
                flag = 1;
            }
        }

        for(int j=1; j<= suffix.size(); j++){
            if(suffix[suffix.size()-j] != filename[filename.size()-j]){
                flag = 1;
            }
        }

        if(prefix.size()+suffix.size() > filename.size()){
            flag = 1;
        }

        if(flag){
            ret.push_back("NE");
        }else{
            ret.push_back("DA");
        }
    }

    for(string it: ret){
        cout << it << "\n";
    }

    return 0;
}