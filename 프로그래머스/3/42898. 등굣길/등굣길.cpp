#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int DistanceDP[102][102];
    int CountDP[102][102];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
        
    for(int i = 0; i <= m + 1; i++){
        DistanceDP[i][0] = -1;
        DistanceDP[i][n + 1] = -1;
    }
    
    for(int i = 0; i <= n + 1; i++){
        DistanceDP[0][i] = -1;
        DistanceDP[m + 1][i] = -1;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            DistanceDP[i][j] = 1000000;
        }
    }
    
    queue<pair<int, int>> myQueue;
    myQueue.push(make_pair(1, 1));
    DistanceDP[1][1] = 1;
    CountDP[1][1] = 1;
    
    while(!myQueue.empty()){
        int curX = myQueue.front().first;
        int curY = myQueue.front().second;
        myQueue.pop();
        
        for(int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            int nextDistance = DistanceDP[curX][curY] + 1;
            
            if(DistanceDP[nextX][nextY] == -1) continue;
            if(nextDistance > DistanceDP[nextX][nextY]) continue;   
            
            bool flag = false;
            for(int j = 0; j < puddles.size(); j++){
                if(nextX == puddles[j][0] && nextY == puddles[j][1]){
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
                        
            if(DistanceDP[nextX][nextY] == nextDistance){
                CountDP[nextX][nextY] = (CountDP[nextX][nextY] + CountDP[curX][curY]) % 1000000007;
            }
            else{
                CountDP[nextX][nextY] = CountDP[curX][curY];
                DistanceDP[nextX][nextY] = nextDistance;   
                myQueue.push(make_pair(nextX, nextY));                 
            }
                                
        }
    }
    
    answer = CountDP[m][n] % 1000000007;
    
    return answer;
}
