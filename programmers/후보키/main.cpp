#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// https://www.youtube.com/watch?v=gCy00NeWag0
int countBits(int n) {
    int ret = 0;
    while(n) {
        if(n & 1)   ret++; // 마지막 비트가 1이면 count
        n = n >> 1; // 마지막 비트를 1개씩 이동하여 없애줌
    }
    return ret;
}

// 1의 개수를 세서 큰거 -> 작은거 순으로 정렬
bool comp(int a, int b) {
    int x = countBits(a);
    int y = countBits(b);
    return x > y;
}

// 유일성을 체크하는 함수
// 선택된 column들(subset)에 대하여 모든 row를 비교하고 겹치는게 없다면 true return
bool check(vector<vector<string> > relation, int rowSize, int colSize, int subset) {
    // relation의 모든 tuple이 유일한지 탐색
    // subset에 해당하는 column들을 조합했을때 모든 tuple이 유일한가?
    for(int i=0; i<rowSize-1; i++) {
        for(int j=i+1; j<rowSize; j++) {
            bool isSame = true; // 같은게 있는가?
            for(int k=0; k<colSize; k++) { // 모든 속성에 대해 탐색하는데 subset에 해당하는것만 탐색하면 된다
                if((subset & 1 << k) == 0)  continue;
                if(relation[i][k] != relation[j][k]) { // 하나라도 다르면 유일함
                    isSame = false;
                    break;
                }
            }
            // 하나라도 다른게 없었음. 실패
            // subset으로는 유일성이 실패
            if(isSame) {
                return false;
            }
        }
    }
    return true;
}
// 1. 유일성을 만족하는 애들을 찾고
// 2. 그 중에서 최소성을 만족하는 애들을 찾는다
int solution(vector<vector<string> > relation) {
    int answer = 0;
    int rowSize = (int)relation.size();
    int colSize = (int)relation[0].size();
    vector<int> candidates; // 유일성 만족 후보
    
    // 0은 공집합이므로 제외
    // i값이 2진수로 따지면 0001 0010 0011 ... 1111 이므로 모든 경우를 탐색할 수 있다
    // 즉 모든 부분집합을 i로 나타낼 수 있다
    for(int i=1; i < (1 << colSize); i++) {
        if(check(relation, rowSize, colSize, i)) {
            // i가 모든 튜플을 유일하게 식별하면 유일성 만족하므로 candidates에 넣겠다
            candidates.push_back(i);
        }
    }
    
    // candidates에 있는 애들은 유일성을 만족하는 애들
    // 여기서 최소성을 만족하는지 걸러줘야 한다
    // 1. 1인 비트가 많은 순서로 정렬
    // 2. 해당 컬럼 포함한 애들 모두 삭제
    sort(candidates.begin(), candidates.end(), comp);
    
    
    while(!candidates.empty()) {
        int n = candidates.back(); // 가장 적은 속성으로 이루어진 후보키가 꺼내진다
        candidates.pop_back();
        answer++;
        
        // 나머지 candidates중에서 해당 속성을 포함한 애들 모두 지워줘야 함
        for(vector<int>::iterator iter = candidates.begin(); iter != candidates.end();) {
            // n에 포함된 모든 비트가 candidates에도 동일하게 켜져있다 // 포함되어있다
            // 최소성을 만족 못 하는것
            if((n & *iter) == n) {
                iter = candidates.erase(iter); // 지우면 다음 이터레이터가 나온다
            } else {
                iter++;
            }
        }
    }
    
    
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<vector<string> > relation;
    relation.assign(6, vector<string>(4,""));
    
    relation[0][0] = "100";
    relation[0][1] = "ryan";
    relation[0][2] = "music";
    relation[0][3] = "2";
    
    relation[1][0] = "200";
    relation[1][1] = "apeach";
    relation[1][2] = "math";
    relation[1][3] = "2";
    
    relation[2][0] = "300";
    relation[2][1] = "tube";
    relation[2][2] = "computer";
    relation[2][3] = "3";
    
    relation[3][0] = "400";
    relation[3][1] = "con";
    relation[3][2] = "computer";
    relation[3][3] = "4";
    
    relation[4][0] = "500";
    relation[4][1] = "muzi";
    relation[4][2] = "music";
    relation[4][3] = "3";
    
    relation[5][0] = "600";
    relation[5][1] = "apeach";
    relation[5][2] = "music";
    relation[5][3] = "2";
    
    cout<<solution(relation);
    
    return 0;
}
