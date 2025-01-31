#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Disk{
    int requestTime;
    int playTime;
    int num;
        
    Disk(int _requestTime, int _playTime, int _num){
        requestTime = _requestTime;
        playTime = _playTime;
        num = _num;            
    }
};

struct CompareForReady{    
    bool operator()(const Disk& a, const Disk& b) const{
        if(a.playTime != b.playTime) return a.playTime > b.playTime;
        else if(a.requestTime != b.requestTime) return a.requestTime > b.requestTime;
        else return a.num > b.num;
    };    
};

struct CompareForRequest{    
    bool operator()(const Disk& a, const Disk& b) const{
        return a.requestTime > b.requestTime;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime = 0;
    priority_queue<Disk, vector<Disk>, CompareForRequest> RequestPQ; 
    priority_queue<Disk, vector<Disk>, CompareForReady> ReadyPQ; 
    
    for(int i = 0; i < jobs.size(); i++){
        RequestPQ.push(Disk(jobs[i][0], jobs[i][1], i));
    }
    
    while(!RequestPQ.empty() || !ReadyPQ.empty()){
        while(!RequestPQ.empty() && RequestPQ.top().requestTime <= curTime){
            ReadyPQ.push(RequestPQ.top());
            RequestPQ.pop();
        }
        
        if(ReadyPQ.empty()){
            curTime++;
            continue;
        }
        
        curTime += ReadyPQ.top().playTime;
        answer += curTime - ReadyPQ.top().requestTime;
        ReadyPQ.pop();
    } 
    
    return answer / jobs.size();
}