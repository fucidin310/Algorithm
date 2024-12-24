#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int DP[501][501];
    
    for(int i = 0; i <= 500; i++){
        for(int j = 0; j <= 500; j++){
            DP[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= triangle.size(); i++){
        for(int j = 1; j <= i; j++){
            DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + triangle[i - 1][j - 1];
            
            if(i == triangle.size()) answer = max(answer, DP[i][j]);
        }
    }
    
    return answer;
}