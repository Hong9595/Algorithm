#include <iostream>
#include <vector>
using namespace std;

int N,M,K,R,C;
vector<vector<int> > graph, sticker;

// sticker 붙을 수 있는지
// 있다면 붙이고 true return
// 없다면 false return
bool check(int curR, int curC) {
    // 현재 좌표 기준으로 스티커 붙을 수 있는지
    // sticker의 Row,Col값은 회전되므로 계속 바뀜
    int stickerR = (int)sticker.size();
    int stickerC = (int)sticker[0].size();
    
    if(curR + stickerR > N)   return false;
    if(curC + stickerC > M)   return false;
    
    // 스티커 안 붙을 경우 graph는 그대로여야 하므로 백업
    vector<vector<int>> temp = graph;
    
    // 현재 좌표부터 스티커 붙이기 수행
    for(int i=0; i<stickerR; i++) {
        for(int j=0; j<stickerC; j++) {
            if(sticker[i][j] == 1) {
                // 스티커 못 붙이는 경우
                if(temp[curR+i][curC+j] == 1) return false;
                // 스티커 붙일 수 있는 경우
                else    temp[curR+i][curC+j] = 1;
            }
        }
    }
    // 스티커 붙였으므로 graph 변경
    graph = temp;
    return true;
}

void rotateSticker() {
    vector<vector<int>> temp = sticker;
    int stickerR = (int)sticker.size();
    int stickerC = (int)sticker[0].size();
    
    sticker.assign(stickerC, vector<int>(stickerR,0));
    
    // 90도 회전
    for(int i=0; i<stickerC; i++) {
        for(int j=0; j<stickerR; j++) {
            sticker[i][j] = temp[stickerR-1-j][i];
        }
    }
}



int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>K;
    
    graph.assign(N, vector<int>(M,0));
    
    // sticker 개수만큼 반복
    for(int i=0; i<K; i++) {
        // sticker가 붙었는가?
        bool flag = false;
        // sticker 입력
        cin>>R>>C;
        sticker.assign(R, vector<int>(C,0));
        for(int j=0; j<R; j++) {
            for(int k=0; k<C; k++) {
                cin>>sticker[j][k];
            }
        }
        
        // 회전(0, 90, 180, 270)
        for(int j=0; j<4; j++) {
            // graph의 모든 좌표에 대하여 왼쪽 위부터 탐색
            for(int r=0; r<N; r++) {
                for(int c=0; c<M; c++) {
                    // sticker가 붙을 가능성이 있다면 탐색
//                    if(graph[r][c] == 0) {
                        // 붙을 수 있는 경우
                        if(check(r, c)) {
                            flag = true;
                            break;
                        }
//                    }
                }
                // stikcer 붙었으면 회전할 필요 없이 break
                if(flag)    break;
            }
            if(flag)    break;
            else    rotateSticker();// sticker 못 붙은 경우 회전
        }
    }
    
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(graph[i][j] == 1)    ans++;
        }
    }
    cout<<ans;
    
    return 0;
}
