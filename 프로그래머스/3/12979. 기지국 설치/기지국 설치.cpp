#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int length = 2 * w + 1;    
    int startPos = 0;
    
    for(int i = 0; i < stations.size(); i++){
        if(stations[i] - w <= startPos + 1){
            startPos = stations[i] + w;
            continue;
        }
        
        int temp = stations[i] - startPos - w - 1;
        
        answer += temp / length;
        if((temp % length) != 0) answer++;
        
        startPos = stations[i] + w;
    }
    
    if(startPos < n){
        int temp = n - startPos;
        
        answer += temp / length;
        if(temp % length != 0) answer++;       
    }

    return answer;
}