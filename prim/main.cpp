#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// https://www.weeklyps.com/entry/프림-알고리즘-Prims-algorithm

const int N = 10001, MAX = 2140000000;
vector<pair<int,int> > ad[N];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // (dist, vertex)

bool selected[N]; // 방문 여부

// 해당 vertex에서 갈 수 있는 모든 간선 pq에 추가(T에 추가)
void addEdge(int vertex) {
    for(auto edge : ad[vertex]) {
        pq.push(edge);
    }
}
long long prim(int pn) {
    long long ret = 0;
    
    for(int i=1; i<=pn; i++) {
        selected[i] = false;
    }
    pq.push({0,1}); // 1번 vertex에서 시작. 가중치는 0
    
    // 정점 개수만큼
    for(int i=1; i<=pn; i++) {
        int minDist = MAX;
        int nextVertex = -1;
        
        while(!pq.empty()) {
            nextVertex = pq.top().second;
            if(selected[nextVertex] == false) { // 방문 안 한 것중 최소 가중치를 가진 노드
                minDist = pq.top().first; // nextWeight
                // 정점이 추가되는 경우(T에 포함)
                ret += minDist;
                selected[nextVertex] = true;
                addEdge(nextVertex);
                break;
            }
            pq.pop();
        }
        // 방문할 수 있는 정점이 없는데 정점 개수만큼 안 돌았다. -> 연결 그래프가 아니다
        if(minDist == MAX)  return (long long)MAX;
//        // 정점이 추가되는 경우(T에 포함)
//        ret += minDist;
//        selected[nextVertex] = true;
//        addEdge(nextVertex);
//        break;
    }

    return ret;
}
int main(int argc, const char * argv[]) {
    return 0;
}
