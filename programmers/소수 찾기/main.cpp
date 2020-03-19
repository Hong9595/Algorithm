#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PRIME_LEN 3000
bool primeArr[PRIME_LEN]={0,}; // true: 소수가 아니다

void checkPrime() {
    for(int i=2; i<PRIME_LEN; i++) {
        if(primeArr[i] == false) { // 소수인 애들
            for(int j=2; i*j < PRIME_LEN; j++) {
                primeArr[i*j] = true;
            }
        }
    }
}
int solution(vector<int> nums) {
    int answer = 0;
    
    checkPrime();
    
    sort(nums.begin(), nums.end(), less<int>());
    int len = (int)nums.size();
    vector<int> combVec(len, 0);
    combVec[0] = combVec[1] = combVec[2] = 1;
    
    do {
        int acc = 0;
        for(int i=0; i<len; i++) {
            if(combVec[i] == 1) acc += nums[i];
        }
        if(primeArr[acc] == false)  answer++;
    } while(prev_permutation(combVec.begin(), combVec.end()));
    
    
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(4);
    
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(4);
    
    cout<<solution(nums);
    return 0;
}
