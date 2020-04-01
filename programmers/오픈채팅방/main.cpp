#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
#include <map>
using namespace std;

map<string,string> m;
queue<pair<string, string> > q;

void check(vector<string> s) {
    if(s[0] == "Enter") {
        m[s[1]] = s[2];
        q.push({s[0], s[1]});
    } else if(s[0] == "Leave") {
        q.push({s[0], s[1]});
    } else if(s[0] == "Change") {
        m[s[1]] = s[2];
    }

}
void print(vector<string>& answer) {
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        string user = m[p.second];
        if(p.first == "Enter") {
            answer.push_back(user + "님이 들어왔습니다.");
        } else if(p.first == "Leave") {
            answer.push_back(user + "님이 나갔습니다.");
        }
    }
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    regex pattern("\\S+");
    smatch matchInfo;
    
    int len = (int)record.size();
    for(int i=0; i<len; i++) {
        string s = record[i];
        vector<string> tempVec;
        while(regex_search(s, matchInfo, pattern)) {
            tempVec.push_back(matchInfo.str());
            s = matchInfo.suffix();
        }
        check(tempVec);
    }
    print(answer);
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    
    solution(record);
    
    return 0;
}
