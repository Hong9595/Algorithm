#include <iostream>
#include <string.h>
using namespace std;

// row col +5 해서 양수 좌표로 바꿈
// (0,0) ~ (10,10) 가능함
bool U[11][11];
bool D[11][11];
bool L[11][11];
bool R[11][11];
int solution(string dirs) {
    int answer = 0;
    memset(U, false, sizeof(U));
    memset(D, false, sizeof(D));
    memset(L, false, sizeof(L));
    memset(R, false, sizeof(R));

    int len = (int)dirs.size();
    // 시작 좌표
    int row = 5;
    int col = 5;

    // 온 방향의 반대 방향도 check해줘야 한다
    for(int i=0; i<len; i++) {
        if(dirs[i] == 'U') {
            if(row-1 < 0 || row-1 > 10 || col < 0 || col > 10)   continue;
            if(U[row-1][col] == false) {
                U[row-1][col] = true;
                D[row][col] = true;
                answer++;
            }
            row--;
        } else if(dirs[i] == 'D') {
            if(row+1 < 0 || row+1 > 10 || col < 0 || col > 10)   continue;
            if(D[row+1][col] == false) {
                D[row+1][col] = true;
                U[row][col] = true;
                answer++;
            }
            row++;
        } else if(dirs[i] == 'L') {
            if(row < 0 || row > 10 || col-1 < 0 || col -1 > 10)   continue;
            if(L[row][col-1] == false) {
                L[row][col-1] = true;
                R[row][col] = true;
                answer++;
            }
            col--;
        } else if(dirs[i] == 'R') {
            if(row < 0 || row > 10 || col+1 < 0 || col +1 > 10)   continue;
            if(R[row][col+1] == false) {
                R[row][col+1] = true;
                L[row][col] = true;
                answer++;
            }
            col++;
        }
    }

    return answer;
}

// https://jayrightthere.tistory.com/entry/프로그래머스-방문-길이
//int map[11][11];
//bool visited[11][11][11][11];
//int dx[4] ={0,0,1,-1};
//int dy[4] = {1,-1,0,0};
//상 하 우 좌
//
//int solution(string dirs)
//{
//    int answer = 0;
//
//    queue<char> q;
//    for (int i = 0; dirs[i]; i++) {
//        q.push(dirs[i]);
//    }
//
//    int x = 5, y = 5;
//
//    while(!q.empty()) {
//        char dir = q.front(); q.pop();
//        int nx = x;
//        int ny = y;
//        if (dir == 'U') {
//            //상
//            nx += dx[0];
//            ny += dy[0];
//        } else if (dir == 'D') {
//            //상
//            nx += dx[1];
//            ny += dy[1];
//        } else if (dir == 'R') {
//            //상
//            nx += dx[2];
//            ny += dy[2];
//        } else if (dir == 'L') {
//            nx += dx[3];
//            ny += dy[3];
//        }
//
//        if (nx < 0 || nx > 10|| ny < 0 || ny > 10 ) continue;
//        // 양방향
//        if (!visited[x][y][nx][ny]) {
//            visited[x][y][nx][ny] = true;
//            visited[nx][ny][x][y] = true;
//            answer++;
//        }
//
//
//        x = nx;
//        y = ny;
//    }
//
//    return answer;
//}



int main(int argc, const char * argv[]) {
    cout<<solution("ULURRDLLU")<<endl;
    cout<<solution("LULLLLLLU")<<endl;
    cout<<solution("LRLRLRLLRRLLRR")<<endl;
    cout<<solution("L")<<endl;
    
    return 0;
}
