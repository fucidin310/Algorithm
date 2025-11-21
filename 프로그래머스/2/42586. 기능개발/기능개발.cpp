#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int lastDays = 0;
    
    for(int i = 0; i < progresses.size(); i++){
        int curDays = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        if(lastDays < curDays){
            answer.push_back(1);
            lastDays = curDays;
        }
        else{
            answer[answer.size() - 1]++;
        }
    }
    
    
    
    return answer;
}