#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> stones, int k, int n){  
    int stack = k;
    
    for(int stone : stones){
        if(stone <= n) stack--;             
        else stack = k; 
        
        if(stack <= 0) return false;       
    }
    
    return true;
}

int solution(vector<int> stones, int k) {    
    int start = 1;
    int end = *max_element(stones.begin(), stones.end());
    
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(isPossible(stones, k, mid)) start = mid + 1;
        else end = mid - 1;
    }    
    
    return start;
}