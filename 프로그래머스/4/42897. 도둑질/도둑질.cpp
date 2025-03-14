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
        if(DP1[i - 2] + money[i] > DP1[i - 1]){
            DP1[i] = DP1[i - 2] + money[i];            
        }
        else{
            DP1[i] = DP1[i - 1];
        }
        
        if(DP2[i - 2] + money[i] > DP2[i - 1]){
            DP2[i] = DP2[i - 2] + money[i];            
        }
        else{
            DP2[i] = DP2[i - 1];
        }
    }
    
    if(DP1[money.size() - 2] > DP2[money.size() - 1]){
        return DP1[money.size() - 2];
    }
    else{
        return DP2[money.size() - 1];
    }
}