#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> cores) {
    int start = 0;
    int end = 50000 * n / cores.size();
    int work = 0;
    
    while(start <= end){
        int mid = (start + end) / 2;
        int tempWork = 0;
        
        for(int core : cores){
            tempWork += mid / core + 1;
        }
        
        if(tempWork >= n){
            end = mid - 1;
            work = tempWork;
        }
        else{
            start = mid + 1;
        }
    }
    
    for(int i = cores.size() - 1; i >= 0; i--){
        if(start % cores[i] != 0) continue;
        
        if(work == n) return i + 1;
        else work--;
    }
}