#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> nodes(n, vector<bool>(n, false));
    
    for(int i = 0; i < results.size(); i++){
        nodes[results[i][0] - 1][results[i][1] - 1] = true;
    }
    
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(nodes[i][k] && nodes[k][j]) nodes[i][j] = true;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(nodes[i][j] || nodes[j][i]) cnt++;
        }
        if(cnt == n - 1) answer++;
    }
    
    return answer;
}