#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    int CameraPos = -30001;
    for(int i = 0; i < routes.size(); i++){
        if(routes[i][0] > CameraPos){
            CameraPos = routes[i][1];
            answer++;
            continue;
        }
        
        if(routes[i][0] <= CameraPos){
            if(routes[i][1] < CameraPos){
                CameraPos = routes[i][1];
            }
        }
    }
        
    return answer;
}