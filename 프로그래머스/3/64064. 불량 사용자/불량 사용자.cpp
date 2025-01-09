#include <string>
#include <vector>

using namespace std;

int answer = 0;    
int bannedSize = 0;
vector<vector<int>> myVec;
vector<int> answerList;

void BackTracking(int index, int save){
    if(index >= bannedSize){
        for(int i = 0; i < answerList.size(); i++){
            if(save == answerList[i]) return;
        }
        
        answerList.push_back(save);
        answer++;
        return;
    }
    
    if(myVec[index].size() == 0){
        BackTracking(index + 1, save);
        return;
    }
    
    for(int i = 0; i < myVec[index].size(); i++){
        if((save & 1 << myVec[index][i]) != 0) continue;
        
        BackTracking(index + 1, save | 1 << myVec[index][i]);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    bannedSize = banned_id.size();
    myVec.resize(bannedSize);
    
    for(int b = 0; b < banned_id.size(); b++){
        for(int u = 0; u < user_id.size(); u++){
            if(user_id[u].size() != banned_id[b].size()) continue;
            
            bool flag = false;
            for(int n = 0; n < user_id[u].size(); n++){
                if(banned_id[b][n] == '*') continue;
                
                if(user_id[u][n] != banned_id[b][n]){
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                myVec[b].push_back(u);
            }
        }            
    }
    
    BackTracking(0, 0);

    return answer;
}