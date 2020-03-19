#include <iostream>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    
    int len = (int)s.size();
    stack<char> st;
    
    for(int i=0; i<len; i++) {
        if(st.empty())   st.push(s[i]);
        else if(st.top() != s[i])   st.push(s[i]);
        else    st.pop();
    }
    
    if(st.empty())  answer = 1;
    else    answer = 0;
    
    return answer;
}
int main(int argc, const char * argv[]) {
//    cout<<solution("baabaa");
    
    cout<<solution("cdcd");
    return 0;
}
