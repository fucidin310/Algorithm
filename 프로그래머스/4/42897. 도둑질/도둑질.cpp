#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int DP1[money.size()];
    int DP2[money.size()];
    
    DP1[0] = money[0];
    DP1[1] = DP1[0];
    DP2[0] = 0;
    DP2[1] = money[1];
    
    for(int i = 2; i < money.size(); i++){
        DP1[i] = max(DP1[i - 2] + money[i], DP1[i - 1]);
        DP2[i] = max(DP2[i - 2] + money[i], DP2[i - 1]);
    }
    
    return max(DP1[money.size() - 2], DP2[money.size() - 1]);
}