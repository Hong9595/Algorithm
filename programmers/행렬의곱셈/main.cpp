#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int rowSize = (int)arr1.size();
    int colSize = (int)arr2[0].size();
    
    answer.assign(rowSize, vector<int>(colSize,0));
    
    int arr1ColSize = (int)arr1[0].size();
    
    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            for(int k=0; k<arr1ColSize; k++) { // arr1ColSize == arr2RowSize
                answer[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
