#include <string>
#include <vector>

using namespace std;

int answer = 0;
int N = 0;

void Backtracking(int index, int openNum){
    if(index >= N){
        if(openNum == 0) answer++;
        return;
    } 
    
    Backtracking(index + 1, openNum + 1);
    if(openNum > 0) Backtracking(index + 1, openNum - 1);
}

int solution(int n) {
    N = n * 2;
    Backtracking(1, 1);
    return answer;
}