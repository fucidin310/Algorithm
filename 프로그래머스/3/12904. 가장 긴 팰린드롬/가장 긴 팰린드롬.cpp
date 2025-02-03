#include <iostream>
#include <string>
using namespace std;

int DP[2500][2500];

int solution(string s)
{
    int answer=0;

    for(int end = 0; end < s.size(); end++){
        for(int start = 0; start <= end; start++){
            //길이가 1이면 1
            if(start == end){
                DP[start][end] = 1;
            }
            else{
                //일단 초기화
                DP[start][end] = 0;
            
                //양 끝이 다를 경우
                if(s[start] != s[end]){
                    
                }
                else{
                    int midStart = start + 1;
                    int midEnd = end - 1;
            
                    //양 끝이 같은데
                    //길이가 2인 경우
                    if(midStart > midEnd){
                        DP[start][end] = 2;
                    }
                    //그 이상인 경우
                    else{
                        //사이 값이 팰린드롬
                        if(DP[midStart][midEnd] > 0){
                            DP[start][end] = DP[midStart][midEnd] + 2;
                        }                
                    }                    
                }                           
            }
            
            //정답 저장
            if(answer < DP[start][end]) answer = DP[start][end];
        }
    }

    return answer;
}