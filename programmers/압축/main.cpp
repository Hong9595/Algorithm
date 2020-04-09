#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string,int> wordMap;
    int cnt = 1;
    for(; cnt<=26; cnt++) {
        string temp = "";
        temp += (char)(65+cnt-1);
        wordMap[temp] += cnt;
    }
    
    int msgLen = (int)msg.size();
    for(int i=0; i<msgLen;) {
        string concatStr = "";
        concatStr += msg[i];
        
        while(wordMap[concatStr] != 0) { // 아직 없는 문자열까지 탐색
            ++i;
            concatStr += msg[i]; // i번째까지 concat됨. i-1까지 있다는 의미 이므로 i번째부터 for문 돌면 됨
        }
        answer.push_back(wordMap[concatStr.substr(0,concatStr.size()-1)]);
        wordMap[concatStr] += cnt;
        cnt++;
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    //    solution("KAKAO");
    //    solution("TOBEORNOTTOBEORTOBEORNOT");
    solution("ABABABABABABABAB");
    return 0;
}

