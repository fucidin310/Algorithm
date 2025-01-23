#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> roadList;
    roadList.resize(n + 1);
    for(vector<int> road : roads){
        roadList[road[0]].push_back(road[1]);
        roadList[road[1]].push_back(road[0]);
    }
    
    vector<int> Distance;
    Distance.resize(n + 1);
    for(int i = 1; i <= n; i++){
        Distance[i] = -1;
    }
    
    queue<int> myQueue;
    Distance[destination] = 0;
    myQueue.push(destination);
    
    while(!myQueue.empty()){
        int curPlace = myQueue.front();
        myQueue.pop();
        
        for(int nextPlace : roadList[curPlace]){
            if(Distance[nextPlace] == -1) {
                Distance[nextPlace] = Distance[curPlace] + 1;
                myQueue.push(nextPlace);
            }            
        }
    }
    
    for(int startPoint : sources){
        answer.push_back(Distance[startPoint]);
    }
    return answer;
}