#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> isVisited;
    isVisited.resize(n, false);
    
    for(int i = 0; i < n; i++){
        if(isVisited[i] == true) continue;
        
        stack<int> myStack;
        myStack.push(i);
        isVisited[i] = true;
        answer++;
        
        while(!myStack.empty()){
            int curIndex = myStack.top();
            myStack.pop();
            
            for(int j = 0; j < n; j++){
                if(isVisited[j] == true || computers[curIndex][j] == 0) continue;
                
                myStack.push(j);
                isVisited[j] = true;
            }
        }
    }
    
    return answer;
}