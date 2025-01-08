#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int size = sticker.size();
        
    //처음 스티커 땐 DP, 0 : 땐거, 1 : 안땐거
    int SF_DP[100000][2];
    //처음 스티커 안 땐 DP
    int NSF_DP[100000][2];
    
    SF_DP[0][0] = sticker[0];
    SF_DP[0][1] = 0;
    
    NSF_DP[0][0] = 0;
    NSF_DP[0][1] = 0;
    
    //마지막 직전까지
    for(int i = 1; i < size - 1; i++){
        SF_DP[i][0] = SF_DP[i - 1][1] + sticker[i];
        SF_DP[i][1] = max(SF_DP[i - 1][0], SF_DP[i - 1][1]);
        
        NSF_DP[i][0] = NSF_DP[i - 1][1] + sticker[i];
        NSF_DP[i][1] = max(NSF_DP[i - 1][0], NSF_DP[i - 1][1]);
    }
            
    //정답
    int maxSF_DP = max(SF_DP[size - 2][0], SF_DP[size - 2][1]);
    int maxNSF_DP = max(NSF_DP[size - 2][0], NSF_DP[size - 2][1]+ sticker[size - 1]);
    answer = max(maxSF_DP, maxNSF_DP);

    return answer;
}