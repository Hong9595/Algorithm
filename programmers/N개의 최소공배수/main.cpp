#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)  return a;
    
    return gcd(b, a % b);
}
int solution(vector<int> arr) {
    int answer = 0;
    
    int len = (int)arr.size();
    answer = 1;
    
    // lcm = a * b / gcd
    for(int i=0; i<len; i++) {
        answer = (answer * arr[i]) / gcd(answer, arr[i]);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> arr;
//    arr.push_back(1);
//    arr.push_back(2);
//    arr.push_back(3);
//
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(14);
    
    cout<<solution(arr);
    
    return 0;
}
