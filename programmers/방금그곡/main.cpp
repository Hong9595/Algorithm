#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

// #붙은 알파벳을 소문자로 변경
string replaceLower(string s) {
    string ret = "";
    int len = (int)s.size();
    for(int i=0; i<len; i++) {
        if(s[i] == '#') {
            char temp = ret.back() + 32;
            ret.pop_back();
            ret.push_back(temp);
            continue;
        }
        ret.push_back(s[i]);
    }
    return ret;
}
// 반복할 시간 계산
int calTime(int startHour, int startMin, int endHour, int endMin) {
    int startTime = startHour * 60 + startMin;
    int endTime = endHour * 60 + endMin;
    
    return endTime - startTime;
}
// 시간순 정렬
bool comp(string s1, string s2) {
    string firstTimeStr = "";
    string latterTimeStr = "";
    
    firstTimeStr = s1[0] + s1[1] + s1[3] + s1[4];
    latterTimeStr = s2[0] + s2[1] + s2[3] + s2[4];

    return firstTimeStr < latterTimeStr;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    regex namePattern("\\s+");
    regex alphaPattern("\[a-zA-Z]+");
    regex numPattern("\[0-9]+");
    smatch matchInfo;
    
    sort(musicinfos.begin(), musicinfos.end(), comp);
    
    // 찾으려는 문자 # -> 소문자로 치환
    string findStr = replaceLower(m);
    int findLen = (int)findStr.size();
    pair<int,string> tempAns = {0,""};
    for(auto s : musicinfos) {
        string temp = s;
        vector<int> timeVec;
        // 시간만 따로 빼서 반복할 횟수를 구해준다
        while(regex_search(temp, matchInfo, numPattern)) {
            timeVec.push_back(stoi(matchInfo.str()));
            temp = matchInfo.suffix();
        }
        // 반복할 시간 횟수
        int loopTimeCnt = calTime(timeVec[0], timeVec[1], timeVec[2], timeVec[3]);
        
        // 출력해줄 문자열
        string compStr = "";
        int i = 12;
        for(i=12; ; i++) {
            if(s[i] == ',') break;
            compStr.push_back(s[i]);
        }
        // 음표
        i++;
        int sLen = (int)s.size();
        string info = "";
        for(; i<sLen; i++) {
            info.push_back(s[i]);
        }
        // #치환
        info = replaceLower(info);
        
        // 음표 재생된 시간만큼 concat
        string playedStr = "";
        int originLen = (int)info.size();
        for(int i=0; i<loopTimeCnt; i++) {
            playedStr += info[i % originLen];
        }
        
        // concat된 음표에 m이 있는지
        for(int i=0; i<loopTimeCnt; i++) {
            if(findStr[0] == playedStr[i]) {
                int j = 0;
                for(; j<findLen; j++) {
                    if(findStr[j] != playedStr[i+j])    break;
                }
                if(j == findLen) { // 찾은 경우
                    if(tempAns.first < loopTimeCnt) {
                        tempAns = {loopTimeCnt, compStr};
                    }
                }
            }
        }
    }
    answer = tempAns.second;
    if(answer == "")    answer = "(None)";
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<string> musicinfos;
//        musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");
//        musicinfos.push_back("12:00,12:14,HELLO,CDEFGAB");
//        cout<<solution("ABCDEFG", musicinfos);
    //
//            musicinfos.push_back("03:00,03:30,FOO,CC#B");
//            musicinfos.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");
//            cout<<solution("CC#BCC#BCC#BCC#B", musicinfos);
    
//            musicinfos.push_back("12:00,12:14,HELLO,C#DEFGAB");
//            musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");
//            cout<<solution("ABC", musicinfos);
    //
    musicinfos.push_back("12:00,13:00,HELLOOO,CDEFGAB");
    musicinfos.push_back("12:00,13:00,HELLO,CDEFGAB");
    cout<<solution("ABCD", musicinfos);
//        musicinfos.push_back("12:00,12:10,HELLOOO,CDCDCDF");
//        cout<<solution("CDCDF", musicinfos);
    
    //    cout<<(int)'A'<<endl<<(int)'a'<<endl;
    return 0;
}


