#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    bool isVisited[20000];
    isVisited[0] = true;
    for(int i = 1; i < n; i++){
        isVisited[i] = false;
    }
    
    vector<vector<int>> edges;
    edges.resize(n);
    for(int i = 0; i < edge.size(); i++){
        edges[edge[i][0] - 1].push_back(edge[i][1] - 1);
        edges[edge[i][1] - 1].push_back(edge[i][0] - 1);
    }
    
    int maxDistance = 0;
    
    //노드, 거리
    queue<pair<int, int>> myQueue;
    myQueue.push(make_pair(0,0));
    
    while(!myQueue.empty()){
        int nodeNum = myQueue.front().first;
        int curDistance = myQueue.front().second;
        myQueue.pop();
        
        if(maxDistance > curDistance) continue;
        
        if(maxDistance < curDistance){
            maxDistance = curDistance;
            answer = 0;
        }
        
        answer++;
        
        for(int i = 0; i < edges[nodeNum].size(); i++){
            int nextNode = edges[nodeNum][i];
            if(isVisited[nextNode]) continue;
            
            myQueue.push(make_pair(nextNode, curDistance + 1));
            isVisited[nextNode] = true;
        }
    }
    
    return answer;
}