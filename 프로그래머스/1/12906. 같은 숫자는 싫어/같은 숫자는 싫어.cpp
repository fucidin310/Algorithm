#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{    
    vector<int> answer;
    
    int lastNum = -1;
    
    for(int n : arr){
        if(lastNum == n) continue;
        
        lastNum = n;
        answer.push_back(n);
    }

    return answer;
}