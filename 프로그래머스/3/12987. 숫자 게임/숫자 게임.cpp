#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int index = 0;
    int size = A.size();
    
    for(int i = 0; i < size; i++){
        if(index >= size) break;
        
        while(index < size){
            if(A[i] < B[index]){
                index++;
                answer++;
                break;
            }
            
            index++;
        }
    }
        
    return answer;
}
