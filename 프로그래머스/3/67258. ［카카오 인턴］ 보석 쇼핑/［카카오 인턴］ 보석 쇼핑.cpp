#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.resize(2);
    
    int maxGemTypes = 0;
    
    unordered_map<string, int> map; 
    for(int i = 0; i < gems.size(); i++){
        auto it = map.find(gems[i]);
        if(it == map.end()){
            map[gems[i]] = 0;
            maxGemTypes++;
        }        
    }
    
    int curGemTypes = 1;
    answer[0] = 0;
    answer[1] = gems.size() - 1;
    
    int startIndex = 0;
    int endIndex = 0;
    map[gems[endIndex]]++;
        
    while(true){   
        if(curGemTypes == maxGemTypes){
            if((endIndex - startIndex) < (answer[1] - answer[0])){
                answer[0] = startIndex;
                answer[1] = endIndex;
            }
        }
        
        if (curGemTypes < maxGemTypes) {
            endIndex++;
            if (endIndex == gems.size()) break;
            if (map[gems[endIndex]] == 0) {
                curGemTypes++;
            }
            map[gems[endIndex]]++;
        }
        else {
            if (map[gems[startIndex]] == 1) {
                curGemTypes--;
            }
            map[gems[startIndex]]--;
            startIndex++;
        }
    }
    
    answer[0]++;
    answer[1]++;
    
    return answer;
}