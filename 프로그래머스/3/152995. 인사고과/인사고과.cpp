#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    //등수는 1부터 시작
    int answer = 1;

    //원호 점수 저장
    int MyAScore = scores[0][0];
    int MyBScore = scores[0][1];
    
    sort(scores.rbegin(), scores.rend());

    //이전 인사점수
    int LastAScore = scores[0][0];
    //나보다 인사점수 높은 사람 중 가장 큰 동료평가
    int LastMaxBScore = 0;
    //나보다 인사점수 높은 사람 혹은 같은 사람 중 가장 큰 동료평가
    int CurMaxBScore = 0;
    
    for(vector<int>& score : scores){   
        //인사점수가 바뀌면
        if(LastAScore > score[0]){
            LastAScore = score[0];
            LastMaxBScore = CurMaxBScore;
        }               

        //내 동료평가가 더 높으면
        if(CurMaxBScore < score[1]){
            CurMaxBScore = score[1];
        }      

        //나보다 인사점수가 높은 사람 중 동료평가가 더 높으면 -> 인센티브 X
        if(LastMaxBScore > score[1]){
            //원호라면
            if(MyAScore == score[0] && MyBScore == score[1]){
                answer = -1;
                break;
            }           
        }
        //인센티브 O                        
        else{
            //원호보다 점수 합이 높으면
            if(MyAScore + MyBScore < score[0] + score[1]){
                //원호 등수 강등
                answer++;            
            }            
        }
    }
    
    return answer;
}
