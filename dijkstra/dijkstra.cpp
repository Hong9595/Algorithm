// boj.kr/1753
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 987654321

int n; // n개의 vertex

// 그래프 정보
// ex) 1번 버텍스라면 1 -> (2번,가중치) -> (3번, 가중치) 이런 형태
vector<vector<pair<int,int> > > adj;

// 가중치 정렬
struct comp {
    bool operator()(pair<int,int> p1, pair<int,int> p2) {
        return p1.second > p2.second;
    }
};

void dijkstra(int start) {
    // 가중치 최솟값을 뽑아내기 위한 우선순위 큐
    priority_queue<pair<int,int>, vector<pair<int,int> >, comp> pq;
    // 각 버텍스에 도달하는데 드는 거리 // MAX로 초기화
    vector<int> dist(n+1, MAX);
    
    // 시작점까지 거리는 0
    dist[start] = 0;
    // 시작점 가중치 0
    pq.push(make_pair(start, 0));
    
//    // 시작점에서 다른 버텍스들까지 가중치 맥스로 초기화
//    for(int i=1; i<=n; i++) {
//        if(i != start)  pq.push(make_pair(i, MAX));
//    }
    
    while(!pq.empty()) {
        int curVertex = pq.top().first;
        int curWeight = pq.top().second;
        pq.pop();
        
        // vertex를 이미 방문 했을 경우. // 이미 거리가 최소일 것
        // 따라서 curWeight가 기존 dist보다 크게 나옴
        if(curWeight > dist[curVertex]) continue;
        
        // 위 경우가 아니라면 첫 방문
        // 현재 갈 수 있는 버텍스중 최소 가중치로 갈 수 있다는 것
        int curVertexSize = (int)adj[curVertex].size();
        for(int i=0; i<curVertexSize; i++) {
            int nextVertex = adj[curVertex][i].first;
            int curToNextWeight = adj[curVertex][i].second;
            
            // 기존의 다음 버텍스까지의 거리가
            // 현재 버텍스 + 현재 버텍스 to 다음 버텍스보다 크다면
            // 갱신
            if(dist[nextVertex] > dist[curVertex] + curToNextWeight) {
                dist[nextVertex] = dist[curVertex] + curToNextWeight;
                pq.push(make_pair(nextVertex, dist[nextVertex]));
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(dist[i] == MAX)  cout<<"INF"<<endl;
        else    cout<<dist[i];
    }
    
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
