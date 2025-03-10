#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; 

    for (int coin : money) {  
        for (int j = coin; j <= n; j++) { 
            dp[j] = (dp[j] + dp[j - coin]) % 1000000007;
        }
    }
    
    return dp[n];
}