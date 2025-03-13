#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    int MyAScore = scores[0][0];
    int MyBScore = scores[0][1];
    
    sort(scores.rbegin(), scores.rend());
    
    int LastAScore = scores[0][0];
    int LastMaxBScore = 0;
    int CurMaxBScore = 0;
    
    for(vector<int>& score : scores){      
        if(LastAScore > score[0]){
            LastAScore = score[0];
            LastMaxBScore = CurMaxBScore;
        }   
        
        if(LastMaxBScore > score[1]){
            if(MyAScore == score[0] && MyBScore == score[1]){
                answer = -1;
                break;
            }
            else{ 
                continue;                
            }            
        }               
        
        if(CurMaxBScore < score[1]){
            CurMaxBScore = score[1];
        }                           
        
        if(MyAScore + MyBScore < score[0] + score[1]){
            answer++;            
        }
    }
    
    return answer;
}