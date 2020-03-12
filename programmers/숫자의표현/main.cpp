#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int start = 1, end = 1;
    int acc = 0;
    while(start <= n) {
        if(acc > n) {
            acc -= start;
            start++;
            continue;
        }
        if(acc == n)    answer++;
        
        acc += end;
        end++;
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    cout<<solution(15);
    return 0;
}
