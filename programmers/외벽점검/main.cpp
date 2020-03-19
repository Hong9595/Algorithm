#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
#define MAX 99999
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = MAX;
    sort(dist.begin(), dist.end(), greater<int>());
    int distLen = (int)dist.size();
    
    
    for(int i=1; i<=distLen; i++) {
        vector<int> compDist(distLen,0);
        for(int j=0; j<i; j++) { // 조합 // 1개 뽑기 ~ distLen개 뽑기
            compDist[j] = 1;
        }
        
        // 1개 뽑기 ~ distLen개 뽑기 경우에서의 순열만큼 반복
        do {
            // curDistVec은 조합의 순열에 해당하는 원소들
            vector<int> curDistVec;
            for(int j=0; j<distLen; j++) {
                if(compDist[j] == 1)    curDistVec.push_back(dist[j]);
            }
            
            do {
                int weakLen = (int)weak.size();
                int curDistLen = (int)curDistVec.size();
                deque<int> weakDq(weak.begin(), weak.end());
                
                for(int k=0; k<weakLen; k++) { // weakLen만큼 순환해가며 반복해줘야 함
                    int idx = 0;
                    int compNum = weakDq[0] + curDistVec[idx];
                    
                    deque<int> copyWeakDq = weakDq;
                    copyWeakDq.push_back(weakDq.front() + n);
                    copyWeakDq.pop_front();
                    weakDq.pop_front();
                    
                    while(idx < curDistLen) {
                        if(weakDq.empty())  break;
                        
                        if(weakDq.front() <= compNum)  {
                            weakDq.pop_front();
                        } else {
                            idx++;
                            compNum = weakDq.front() + curDistVec[idx];
                        }
                    }
                    if(weakDq.empty())    {
                        answer = min(answer, curDistLen);
                        break;
                    }
                    weakDq = copyWeakDq;
                }
            } while(prev_permutation(curDistVec.begin(), curDistVec.end()));
        } while(prev_permutation(compDist.begin(), compDist.end()));
    }
    if(answer == MAX) answer = -1;
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<int> weak;
    vector<int> dist;
    
//    weak.push_back(1);
//    weak.push_back(5);
//    weak.push_back(6);
//    weak.push_back(10);
//
//    dist.push_back(1);
//    dist.push_back(2);
//    dist.push_back(3);
//    dist.push_back(4);
    
//    weak.push_back(1);
//    weak.push_back(3);
//    weak.push_back(4);
//    weak.push_back(9);
//    weak.push_back(10);
//
//    dist.push_back(3);
//    dist.push_back(5);
//    dist.push_back(7);
//
//    cout<<solution(12, weak, dist);
    
//    weak.push_back(1);
//    weak.push_back(5);
//    weak.push_back(10);
//    weak.push_back(16);
//    weak.push_back(22);
//    weak.push_back(25);
//
//    dist.push_back(3);
//    dist.push_back(4);
//    dist.push_back(6);
//
//    cout<<solution(50, weak, dist);
    
//    weak.push_back(1);
//    weak.push_back(5);
//    weak.push_back(10);
//    weak.push_back(12);
//    weak.push_back(22);
//    weak.push_back(25);
//
//    dist.push_back(4);
//    dist.push_back(3);
//    dist.push_back(2);
//    dist.push_back(1);
//
//    cout<<solution(50, weak, dist);
    
    weak.push_back(1);
    dist.push_back(6);
    cout<<solution(50, weak, dist);
    return 0;
}
