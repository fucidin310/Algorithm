#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    long long maxSum = 0;
    long long minSum = 0;
    long long curSum = 0;
    
    for(int i = 0; i < sequence.size(); i++){
        int sequenceValue = sequence[i];
        if(i % 2 == 0) sequenceValue *= -1;
        
        curSum += sequenceValue;
        
        if(answer < curSum) answer = curSum;
        if(answer < - curSum) answer = - curSum;
        if(answer < (curSum - minSum)) answer = (curSum - minSum);
        if(answer < - (curSum - maxSum)) answer = - (curSum - maxSum);
        
        if(maxSum < curSum) maxSum = curSum;
        if(minSum > curSum) minSum = curSum;        
    }
    
    return answer;
}