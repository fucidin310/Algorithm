#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int temp = s / n;
    
    if(temp == 0){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0; i < n; i++){
        answer.push_back(temp);
    }
    
    for(int i = 0; i < s - temp * n; i++){
        answer[n - 1 - i] += 1;
    }
    
    return answer;
}