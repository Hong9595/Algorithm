#include <iostream>
#include <vector>
#include <regex>
#include <map>
#include <algorithm>

using namespace std;

bool comp(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}
//vector<int> solution(string s) {
//    vector<int> answer;
//
////    vector<string> sortStringVec;
//
//    int len = (int)s.size();
//    vector<vector<int> > sortVec(len);
//
//    int idx = 0;
//    string temp = "";
//    char prev = ' ';
//    for(int i=0; i<len-1; i++) {
//        if(s[i] >= '0' && s[i] <= '9') { // 숫자일 경우 concat
//            temp += s[i];
//        } else if((s[i] == ',' && prev != '}')) {
//            sortVec[idx].push_back(stoi(temp));
//            temp = "";
//        } else if(s[i] == '}') {
//            sortVec[idx].push_back(stoi(temp));
//            temp = "";
//            idx++;
//        }
//        prev = s[i];
//    }
//    vector<vector<int> > resizeSortvec;
//    resizeSortvec.assign(sortVec.begin(), sortVec.begin() + idx);
//
//    sort(resizeSortvec.begin(), resizeSortvec.end(), comp);
//    map<int,int> m;
//    int sortLen = (int)resizeSortvec.size();
//    for(int i=0; i<sortLen; i++) {
//        int eachLen = (int)resizeSortvec[i].size();
//        for(int j=0; j<eachLen; j++) {
//            if(m[resizeSortvec[i][j]] == 0) {
//                m[resizeSortvec[i][j]] += 1;
//                answer.push_back(resizeSortvec[i][j]);
//            }
//        }
//    }
////    for(int i=0; i<answer.size(); i++) {
////        cout<<answer[i]<<endl;
////    }
//    return answer;
//}


//강산이형 {{1,2,3}} 이걸 정규식 써서
//1따로 2따로 3따로 말고
//123으로 뽑아올 수 있을까요??
// {{1,2,3},{2,111},{1,2,4,3},{2}}
// 1,2,3 뽑고  그 다음번에 2,111 그 다음에 1,2,4,3 이런식으로 뽑아서 진행하고 싶은데 방법이 있을까여
// \\d+로 뽑으면 1 -> 2 -> 3 -> 2 -> 111 -> ... 형태라서요


int main(int argc, const char * argv[]) {
//    solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    solution("{{20,111},{111}}");
//    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
//    string temp = "";
//    if(temp == "") {
//        cout<<"TEMP IS EMPTY"<<endl;
//    }
    return 0;
}

