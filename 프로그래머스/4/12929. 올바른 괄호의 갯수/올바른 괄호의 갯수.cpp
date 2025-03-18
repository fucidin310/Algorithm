#include <string>
#include <vector>

using namespace std;

int answer = 0;
int N = 0;

void DFS(int index, int openNum){
    if(index >= N){
        if(openNum == 0) answer++;
        return;
    } 
    
    if(N - index < openNum) return;
    
    if(N - index - openNum % 2 == 1) return;
    
    DFS(index + 1, openNum + 1);
    if(openNum > 0) DFS(index + 1, openNum - 1);
}

int solution(int n) {
    N = n * 2;
    DFS(1, 1);
    return answer;
}