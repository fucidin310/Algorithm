#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(int i = 0; i < works.size(); i++){
        pq.push(works[i]);
    }
    
    for(int i = 0; i < n; i++){
        int temp = pq.top();
        pq.pop();
        if(temp > 0) temp--;
        pq.push(temp);
    }
    
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}