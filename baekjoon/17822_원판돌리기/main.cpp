#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

// x번 판을 d방향으로 k칸 회전
struct rotateInfo {
    int x;
    int d;
    int k;
};

struct circleInfo {
    int deleteVal;
    int circleNumber;
    int index;
    
};

int N,M,T;
vector<deque<int>> dqVec;
vector<vector<bool> > visit;
// 시계방향 회전
void rotateClock(int x, int k) {
    if(k == M)  return;
    for(int i=0; i<k; i++) {
        int temp = dqVec[x].back();
        dqVec[x].pop_back();
        dqVec[x].push_front(temp);
    }
}

// 반시계방향 회전
void rotateCounterclock(int x, int k) {
    if(k == M)  return;
    for(int i=0; i<k; i++) {
        int temp = dqVec[x].front();
        dqVec[x].pop_front();
        dqVec[x].push_back(temp);
    }
}
// bfs시에 조건 체크
void check(queue<circleInfo>& q, int deleteVal, int circleNum, int index) {
    dqVec[circleNum][index] = -1;
    q.push({deleteVal, circleNum, index});
}
// 인접한거 없는 경우에 평균값 구해서 원소값들 바꿔줌
void modulateAvr() {
    int ans = 0;
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(dqVec[i][j] != -1){
                ans += dqVec[i][j];
                cnt ++;
            }
        }
    }
    float avr = (float) ans / cnt;
    ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(dqVec[i][j] != -1){
                if(dqVec[i][j] > avr) {
                    dqVec[i][j] -= 1;
                } else if(dqVec[i][j] < avr) {
                    dqVec[i][j] += 1;
                }
            }
        }
    }
}

// 인접한거 다 지워주는 bfs
// 인접하다면 값을 -1로 바꿔놓는다
bool checkBfs(int cirNum, int idx) {
    queue<circleInfo> q;
    // 지울 숫자, 몇 번째 판, 해당 판의 인덱스
    q.push({dqVec[cirNum][idx], cirNum, idx});
    int cnt = 0;
    while(!q.empty()) {
        auto temp = q.front();
        int deleteVal = temp.deleteVal;
        int circleNum = temp.circleNumber;
        int index = temp.index;
        q.pop();
        
        int left = index - 1, right = index + 1;
        int down = circleNum - 1, up = circleNum + 1;
        
        if(left == -1)  left = M-1;
        if(right == M)  right = 0;
        
        if(dqVec[circleNum][left] == deleteVal) {
            check(q, deleteVal, circleNum, left);
            cnt++;
        }
        if(dqVec[circleNum][right] == deleteVal) {
            check(q, deleteVal, circleNum, right);
            cnt++;
        }
        if(down == -1) { // 첫 원판이므로 up만
            if(dqVec[up][index] == deleteVal) {
                check(q, deleteVal, up, index);
                cnt++;
            }
        } else if(up == N) { // 마지막 원판이므로 down만
            if(dqVec[down][index] == deleteVal) {
                check(q, deleteVal, down, index);
                cnt++;
            }
        } else { // 위아래 다
            if(dqVec[up][index] == deleteVal) {
                check(q, deleteVal, up, index);
                cnt++;
            }
            if(dqVec[down][index] == deleteVal) {
                check(q, deleteVal, down, index);
                cnt++;
            }
        }
    }
    return cnt;
}

// 합 계산
int sum() {
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(dqVec[i][j] != -1)   ans += dqVec[i][j];
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // 원판 크기, 원판에 적힌 숫자 개수, 총 회전 수
    cin>>N>>M>>T;
    dqVec.assign(N, deque<int>(M,0));
    
    // 원판 입력
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>dqVec[i][j];
        }
    }
    
    // 회전 정보 입력
    vector<rotateInfo> rotateVec;
    for(int i=0; i<T; i++) {
        int x,d,k;
        cin>>x>>d>>k;
        rotateVec.push_back({x,d,k});
    }
    
    int cnt = 0;
    for(int i=0; i<T; i++) {
        cnt = 0;
        auto t = rotateVec[i];
        if(t.d == 0) { // 시계 방향
            // 판 회전
            int k = 2;
            for(int j = t.x; j <= N; k++) {
                rotateClock(j-1, t.k);
                j = t.x * k;
            }
            // 회전했으므로 삭제
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    if(dqVec[i][j] != -1) {
                        cnt += checkBfs(i, j);
                    }
                }
            }
            
        } else { // 반시계 방향
            // 판 회전
            int k = 2;
            for(int j = t.x; j <= N; k++) {
                rotateCounterclock(j-1, t.k);
                j = t.x * k;
            }
            
            // 회전했으므로 삭제
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    if(dqVec[i][j] != -1) {
                        cnt += checkBfs(i, j);
                    }
                }
            }
        }
        // 인접한게 없다
        // 평균값으로 조정해준다
        if(cnt == 0)    modulateAvr();
    }
    // 모든 과정이 끝났다면 계산
    cout<<sum();
    
    return 0;
}


