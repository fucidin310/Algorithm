#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Find(int index, int unionArr[]){
    if(unionArr[index] == index) return index;
    
    return unionArr[index] = Find(unionArr[index], unionArr);
}

void Union(int FirstIndex, int SecondIndex, int unionArr[]){
    unionArr[Find(SecondIndex, unionArr)] = Find(FirstIndex, unionArr);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    int unionArr[100];
    for(int i = 0; i < n; i++){
        unionArr[i] = i;
    }
    
    sort(costs.begin(), costs.end(), 
         [](vector<int>& a, vector<int>& b){
             return a[2] < b[2];
         });
    
    int BridgeCount = 0;
    
    for(int i = 0; i < costs.size(); i++){
        if(Find(costs[i][0], unionArr) == Find(costs[i][1], unionArr)) continue;
        
        Union(costs[i][0], costs[i][1], unionArr);
        BridgeCount++;
        answer += costs[i][2];
                
        if(BridgeCount == n - 1) break;
    }    
    
    return answer;
}