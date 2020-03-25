#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
    int color;
    int val; // bfs 반복 수
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N,M,G,R;
// (값, bfs횟수)
// 값은 0(호수) 1(배양액 x) 2(배양액) 3(초록) 4(빨강)
vector<vector<pair<int,int> > > graph;
vector<int> syrup; // 순열을 위한 벡터
vector<pair<int,int> > syrupLoc; // 배양액 놓을 수 있는 좌표 목록
int syrupCnt = 0;
int ans = -1;

void bfs() {
    do {
        int tempAns = 0;
        queue<Node> q;
        vector<vector<pair<int,int> > > backUp = graph;
        for(int i=0; i<syrupCnt; i++) {
            // 배양액 놓을 수 있는 경우라면
            // q에 (배양액 좌표, 색깔, bfs횟수) push
            if(syrup[i] != 0) {
                q.push({syrupLoc[i].first, syrupLoc[i].second, syrup[i], 0});
                graph[syrupLoc[i].first][syrupLoc[i].second] = {syrup[i], 0};
            }
        }
        
        while(!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int color = q.front().color;
            int val = q.front().val;
            q.pop();
            // 꽃이 핀 경우
            if(graph[x][y].second == -1)    continue;
            
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M)  continue;
                
                if(graph[nx][ny].first == 0)    continue; // 호수
                if(graph[nx][ny].first == 1 || graph[nx][ny].first == 2) { // 1 or 2인 경우는 방문 가능한 곳. 방문할 때마다 color로 덮어줄 것이므로.
                    graph[nx][ny].first = color;
                    graph[nx][ny].second = val + 1;
                    q.push({nx, ny, color, val+1});
                } else { // 3,4 // 배양액이 뿌려져 있는 경우
                    if(graph[nx][ny].first != color) { // 색이 다르고
                        if(graph[nx][ny].second != 0) { // 배양액이 처음 뿌려진 케이스도 아니고
                            if(graph[nx][ny].second == val + 1) { // bfs 횟수도 같다면
                                graph[nx][ny].first = 0; // 꽃이 피었으므로 더이상 방문 못 하게 호수로 변경
                                // queue에 이놈이 있다면 뽑아줘야되므로
                                graph[nx][ny].second = -1;
                                tempAns++;
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans, tempAns);
        graph = backUp;
    } while(next_permutation(syrup.begin(), syrup.end()));
}

int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>M>>G>>R;
    
    graph.assign(N, vector<pair<int,int> >(0, {0,0}));
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int temp;
            cin>>temp;
            if(temp == 2) {
                syrupCnt++;
                syrupLoc.push_back({i,j});
            }
            graph[i].push_back({temp, 0}); // (땅 값, bfs 0번)
        }
    }
    // syrup 초기화
    // 5칸중 4칸에 배양액을 뿌린다고 해보자
    // 1. 들어갈 수 있는 4칸을 구하는 경우의 수 // 5C4
    // 2. 해당 좌표에서 순열 // 4!
    // 5C4 * 4!
    // 이걸 0 3 3 4 4로 만들어 놓고 순열을 돌리면 된다.
    // 0은 배양액이 안 뿌려지는 좌표. next_permutation 돌리면 3,4에 대해 중복 제거도 가능해짐
    syrup.assign(syrupCnt, 0);
    for(int i=0; i<G; i++) {
        syrup[i] = 3;
    }
    for(int i=G; i<G+R; i++) {
        syrup[i] = 4;
    }
    sort(syrup.begin(), syrup.end());
    
    bfs();
    
    cout<<ans<<endl;
    
    
    return 0;
}
