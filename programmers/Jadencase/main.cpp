#include <iostream>
#include <regex>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";

    // 숫자0개 이상 + 문자열 + 공백 0개 이상
    regex pattern("\\d{0,}\\S+\\s{0,}");
    smatch matchInfo;

    while(regex_search(s, matchInfo, pattern)) {
        string temp = matchInfo.str();
        int len = (int)temp.size();
        // 소문자 -> 대문자
        if(temp[0] >= 'a' && temp[0] <= 'z') temp[0] -= 32;

        // 나머지는 모두 소문자(대문자인 경우)
        for(int i=1; i<len; i++) {
            if(temp[i] >= 'A' && temp[i] <= 'Z') temp[i] += 32;
        }
        answer += temp;
        s = matchInfo.suffix();
    }
    return answer;
}

//string solution(string s)
//{
//    string answer = "";
//
//    for(int i = 0; i < s.size(); i++)
//    {
//        if(s[i] == ' ')
//        {
//            answer += s[i];
//            continue;
//        }
//        else
//        {
//            // 공백 이후 첫문자 or 맨 첫문자
//            if(i == 0 || s[i-1] == ' ')
//            {
//                // 첫문자가 소문자인 경우 -> 대문자
//                if('a' <= s[i] && s[i] <= 'z')
//                {
//                    s[i] = s[i]-32;
//                }
//            }
//            // 이어지는 문자가 대문자인 경우 -> 소문자
//            else
//            {
//                if('A' <= s[i] && s[i] <= 'Z')
//                {
//                    s[i] = s[i]+32;
//                }
//            }
//        }
//
//        answer += s[i];
//    }
//
//    return s;
//}
int main(int argc, const char * argv[]) {
    string s = "for the last week";
//    string s = "3people unFollowed me";
//    string s = "322aa 2123he LAST wEEk";
//    string s = "a a a a b  ";
    cout<<solution(s)<<endl;
    
    return 0;
}
