#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

// LRU는 참조되면 순서가 바뀌는것을 주의!!
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int len = (int)cities.size();
    for(int i=0; i<len; i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
    }

    unordered_map<string, int> m; // 캐슁 되어있는지 유무
    list<string> li; // cache되어있는 string 관리
    
    if(cacheSize == 0)  return 5 * len;
    
    for(int i=0; i<len; i++) {
        if(m[cities[i]] == 0) { // cache miss
            if(li.size() == cacheSize) { // cache miss + lru
                m[li.front()] = 0;
                li.pop_front();
            }
            li.push_back(cities[i]);
            m[cities[i]] = 1;
            answer += 5;
        } else { // cache hit // 참조됐으므로 lru 순서 바뀜
            li.erase(find(li.begin(), li.end(), cities[i]));
            li.push_back(cities[i]);
            answer += 1;
        }
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<string> cities;
//    cities.push_back("Jeju");
//    cities.push_back("Pangyo");
//    cities.push_back("Seoul");
//    cities.push_back("NewYork");
//    cities.push_back("LA");
//    cities.push_back("Jeju");
//    cities.push_back("Pangyo");
//    cities.push_back("Seoul");
//    cities.push_back("NewYork");
//    cities.push_back("LA");
//    cout<<solution(3, cities);

//    cities.push_back("Jeju");
//    cities.push_back("Pangyo");
//    cities.push_back("Seoul");
//    cities.push_back("Jeju");
//    cities.push_back("Pangyo");
//    cities.push_back("Seoul");
//    cities.push_back("Jeju");
//    cities.push_back("Pangyo");
//    cities.push_back("Seoul");
//    cout<<solution(3, cities);
    
//    cities.push_back("Jeju");
//    cities.push_back("Je");
//    cities.push_back("Jej");
//    cities.push_back("Jeju");
//    cities.push_back("Jeju");
//    cities.push_back("Jeju");
//    cities.push_back("Jeju");
//    cities.push_back("Jeju");
//    cities.push_back("Jeju");
//    cities.push_back("Jeju");
//    cities.push_back("Jeju");
//    cout<<solution(1, cities);
    return 0;
}
