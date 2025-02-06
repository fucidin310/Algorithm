#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int minIndex = 0;
    for(int i = 1; i < a.size(); i++){
        if(a[minIndex] > a[i]) minIndex = i;
    }
    answer++;
    
    int leftMinIndex = 0;
    if(minIndex != leftMinIndex) answer++;
    for(int i = leftMinIndex + 1; i < minIndex; i++){
        if(a[leftMinIndex] > a[i]){
             leftMinIndex = i;  
             answer++;
        }      
    }
    
    int rightMinIndex = a.size() - 1;
    if(minIndex != rightMinIndex) answer++;
    for(int i = rightMinIndex - 1; i > minIndex; i--){
        if(a[rightMinIndex] > a[i]){
             rightMinIndex = i;  
             answer++;
        }      
    }
    
    return answer;
}