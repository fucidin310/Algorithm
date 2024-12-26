#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> GetNextWords(string curWord, vector<string> words){
    vector<int> output;
    
    for(int i = 0; i < words.size(); i++){
        int equalWordNum = 0;
        
        for(int j = 0; j < curWord.size(); j++){
            if(curWord[j] != words[i][j]){
                equalWordNum++;
            }
        }
        
        if(equalWordNum == 1) output.push_back(i);
    }
    
    return output;
}

int solution(string begin, string target, vector<string> words) {
    int DP[words.size()];
    priority_queue<pair<int, int>> pq;  
    
    bool flag = false;
    for(int i = 0; i < words.size(); i++){
        if(words[i] == target) flag = true;
    }
    if(!flag) return 0;
        
    vector<int> temp = GetNextWords(begin, words);
    
    for(int i = 0; i < temp.size(); i++){
        if(words[temp[i]] == target){
            return 1;
        }
        
        pq.push(make_pair(1, temp[i]));
        DP[i] = 1;
    }
    
    while(!pq.empty()){
        int curIndex = pq.top().second;
        int curDistance = pq.top().first;
        pq.pop();
        
        vector<int> temp = GetNextWords(words[curIndex], words);
        
        for(int i = 0; i < temp.size(); i++){
            if(words[temp[i]] == target){
                return curDistance + 1;
            }
            
            if(DP[temp[i]] == 0 || DP[temp[i]] > (curDistance + 1)){
                DP[temp[i]] = curDistance + 1;
                pq.push(make_pair(curDistance + 1, temp[i]));
            }
        }
    }
    
    return 0;
}