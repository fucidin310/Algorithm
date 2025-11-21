#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<pair<int, int>> myQueue;
    
    myQueue.push(make_pair(0 ,numbers[0]));
    myQueue.push(make_pair(0 ,-numbers[0]));
    
    for(int i = 1; i < numbers.size() - 1; i++){
        while(myQueue.front().first < i){
            int curValue = myQueue.front().second;
            myQueue.pop();
            myQueue.push(make_pair(i ,curValue + numbers[i]));
            myQueue.push(make_pair(i ,curValue - numbers[i]));
        }
    }
    
    int lastNum = numbers[numbers.size() - 1];
    while(!myQueue.empty()){
        int curValue = myQueue.front().second;
        myQueue.pop();
        if(curValue + lastNum == target) answer++;
        if(curValue - lastNum == target) answer++;        
    }
    
    return answer;
}