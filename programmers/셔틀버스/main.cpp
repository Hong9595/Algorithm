#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    // timetable[0][0], [0][1] == 시간
    // [0][2], [0][3] == 분
    priority_queue<int, vector<int>, greater<int>> timetablePQueue;
    int len = (int)timetable.size();
    
    // 시간으로 잘라서 priority queue에 오름차순으로 정리
//    regex pattern("\\d+");
//    smatch matchInfo;
//    for(int i=0; i<len; i++) {
//        string temp;
//        while(regex_search(timetable[i], matchInfo, pattern)){
//            temp += matchInfo.str();
//            timetable[i] = matchInfo.suffix();
//        }
//        timetablePQueue.push(stoi(temp));
//    }
    for(int i=0; i<len; i++) {
        string temp = "";
//        temp = timetable[i][0] + timetable[i][1] + timetable[i][3] + timetable[i][4];
        
        temp += timetable[i][0];
        temp += timetable[i][1];
        temp += timetable[i][3];
        temp += timetable[i][4];

        cout<<temp;
        timetablePQueue.push(stoi(temp));
    }
    
    
    int cnt = 0; // 셔틀에 태운 크루 수
    int minTime = 900; // minTime은 마지막 정답 비교용
    int curTime = 900 - t; // 09:00부터 시작하기 위함
    // n번 도는 셔틀에 태우는 작업
    // 셔틀이 n번 돌거나, 크루가 모두 탄 경우(pq.empty())에 종료된다
    while(n != 0) {
        bool pqEmptyFlag = false;
        curTime += t; // 09:00부터 시작하여 t분씩 더해간다
        if(curTime % 100 == 60) curTime += 40; // 60분이라면 1시간 추가
        
        cnt = 0; // 뽑는 숫자
        
        while(cnt < m && timetablePQueue.top() <= curTime) { // 셔틀에 태운 숫자가 m보다 작고 && 태울 수 있는 크루가 남아 있다면 => 셔틀에 태운다
            if(timetablePQueue.empty()){ // 이미 전체 크루를 태운 경우
                pqEmptyFlag = true;
                break;
            }
            minTime = timetablePQueue.top(); // 정답 구할 때 사용 -> 셔틀에 태운 크루 숫자 == m인 경우에는 마지막 크루가 탄 시간 -1이 답이어야된다
            timetablePQueue.pop(); // 태운다
            cnt++; // 태운 크루수 증가
        }
        if(pqEmptyFlag) break;
        n--;
    }
    
    // HH:MM 형태가 아니므로 tempAns에 담는다
    // 셔틀 운행이 끝난 경우(n == 0 || pq.empty() )
    // cnt가 m이면 마지막으로 태운 크루보다 -1시간이 최댓값
    // cnt가 m보다 작다면 셔틀 배치 시간(curTime)에 타는것이 최댓값
    int tempAns;
    if(cnt == m){ //
        tempAns = minTime - 1;
        if(tempAns % 100 == 99) tempAns -= 40; // 99분이라면 59분으로 변경
    } else    tempAns = curTime;
    
    
    // HH:MM 형태로 만들기
    int div = 1000;
    for(int i=0; i<5; i++) {
        if(i == 2) {
            answer.push_back(':');
            continue;
        }
        answer.push_back(tempAns / div + '0');
        tempAns -= ((tempAns / div) * div);
        div /= 10;
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<string> timetable;
//    timetable.push_back("08:00");
//    timetable.push_back("08:01");
//    timetable.push_back("08:02");
//    timetable.push_back("08:03");
//    cout<<solution(1,1,5,timetable);
    
//    timetable.push_back("09:10");
//    timetable.push_back("09:09");
//    timetable.push_back("08:00");
//    cout<<solution(2,10,2,timetable);
    
    
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    cout<<solution(10,60,45,timetable);

    return 0;
}
