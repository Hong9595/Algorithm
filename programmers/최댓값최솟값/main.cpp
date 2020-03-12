#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

string solution(string s) {
    string answer = "";

    regex pattern("-?\\d+");
    smatch matchInfo;
    vector<int> v;
    string ansStr;

    while(regex_search(s, matchInfo, pattern)){
        v.push_back(stoi(matchInfo.str()));
        s = matchInfo.suffix();
    }

    sort(v.begin(), v.end());
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v.back());
    return answer;
}

// string에서 특정 문자 지우기
//void removeSpace() {
//    string str = "1 2 3 4";
//    //    remove(str.begin(), str.end(), ' ');
//    str.erase(remove(str.begin(), str.end(), ' '), str.end());
//    cout<<str;
//
//}

int main(int argc, const char * argv[]) {
//    cout<<solution("1 2 3 4");
//    cout<<solution("-1 -2 -3 -4");
    cout<<solution("-1 -1 -1 -1 0 12 -20");
    return 0;
}
