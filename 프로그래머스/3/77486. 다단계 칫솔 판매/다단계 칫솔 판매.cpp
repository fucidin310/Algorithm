#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    answer.resize(enroll.size());
    
    unordered_map<string, int> nameMap;
    for(int i = 0; i < enroll.size(); i++){
        nameMap[enroll[i]] = i;
    }
    
    vector<int> edges;
    for(int i = 0; i < referral.size(); i++){
        if(referral[i] == "-") edges.push_back(-1);
        else edges.push_back(nameMap[referral[i]]);
    }
    
    for(int i = 0; i < seller.size(); i ++){
        int curName = nameMap[seller[i]];
        int curMoney = amount[i] * 100;
        
        while(true){
            answer[curName] += (curMoney - curMoney / 10);
            curMoney = curMoney / 10;
            
            if(curMoney == 0) break;
            
            curName = edges[curName];
            if(curName == -1) break;
        }
    }
    
    return answer;
}