#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    
    vector<int> sum(cookie.size() + 1);
    sum[0] = cookie[0];
    for(int i = 1; i <= cookie.size(); i++){
        sum[i] = sum[i - 1] + cookie[i - 1];
    }
    
    for(int m = 1; m <= cookie.size(); m++){
        int i = m;
        int r = m + 1;
        
        while(true){
            if(i < 1 || r > cookie.size()) break;
            
            int firstSon = sum[m] - sum[i - 1];
            int secondSon = sum[r] - sum[m];
            
            if(firstSon == secondSon){
                answer = max(answer, firstSon);
                i--;
                r++;
            }
            else if(firstSon > secondSon){
                r++;
            }
            else{
                i--;
            }
        }
    }
    
    return answer;
}