#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> tempArr;
    
    for(int i = 0; i < operations.size(); i++){        
        
        if(operations[i][0] == 'I'){
            tempArr.push_back(stoi(operations[i].substr(2)));
        }
        else{
            if(tempArr.size() == 0) continue;
            
            sort(tempArr.begin(), tempArr.end());
            
            if(operations[i][2] == '1'){
                tempArr.erase(tempArr.begin() + tempArr.size() - 1);    
            }
            else{  
                tempArr.erase(tempArr.begin());    
            }
        }
    }
    
    sort(tempArr.begin(), tempArr.end());
    
    if(tempArr.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(tempArr[tempArr.size() - 1]);
        answer.push_back(tempArr[0]);         
    }   
    
    return answer;
}