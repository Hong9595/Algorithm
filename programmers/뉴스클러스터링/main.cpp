#include <iostream>
#include <string>
#include <map>
using namespace std;

char check(char c) {
    if(c >= 'a' && c <= 'z') {
        return c-32;
    } else if(c >= 'A' && c <= 'Z') {
        return c;
    } else return 0;
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string,int> m, m2;
    
    int str1Len = (int)str1.size();
    int str2Len = (int)str2.size();
    
    for(int i=0; i<str1Len-1; i++) {
        char c1 = check(str1[i]);
        char c2 = check(str1[i+1]);
        
        if(c1 == 0 || c2 == 0)  continue;
        
        string temp = "";
        temp += c1;
        temp += c2;
        m[temp] += 1;
    }
    
    for(int i=0; i<str2Len-1; i++) {
        char c1 = check(str2[i]);
        char c2 = check(str2[i+1]);
        
        if(c1 == 0 || c2 == 0)  continue;
        
        string temp = "";
        temp += c1;
        temp += c2;
        m2[temp] += 1;
    }
    
    if(m.size() == 0 && m2.size() == 0) return 65536;
    
    double intersectionCnt = 0;
    double unionCnt = 0;
    
    map<string,int>::iterator iter = m.begin();
    while(iter != m.end()) {
        string temp = (*iter).first;
        if(m2[(*iter).first] != 0) { // 교집합
            intersectionCnt++;
            unionCnt++;
            m2[(*iter).first]--;
        } else { // 합집합
            unionCnt++;
        }
        (*iter).second--;
        if((*iter).second == 0) iter++;
    }
    
    iter = m2.begin();
    while(iter != m2.end()) {
        if((*iter).second != 0) unionCnt += (*iter).second;
        iter++;
    }
    answer = (int)((intersectionCnt / unionCnt) * 65536);
    return answer;
}
int main(int argc, const char * argv[]) {
    cout<<solution("AB", "ABC");
    
    // transform, isalpha, isnumber등의 함수가 존재
    string str1 = "AD2_D";
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    cout<<endl<<str1<<endl;
    if(isalpha('a')){
        cout<<"GOOD"<<endl;
    }
    if(isnumber('3')){
        cout<<"GOOD"<<endl;
    }
//    cout<<solution("FRANCE", "french");
//    cout<<solution("E=M*C^2", "e=m*c^2");
    return 0;
}
