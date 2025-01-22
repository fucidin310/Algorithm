#include <string>
#include <vector>

using namespace std;

long long BinearySearch(long long start, long long end, long long value, vector<int>& times){
    long long tempNum = 0;
    
    if(start > end){
        return start;
    }
    
    long long mid = start + (end - start) / 2;
    for(int i = 0; i < times.size(); i++){
        tempNum += mid / times[i];
    }
    
    if(tempNum < value) start = mid + 1;
    else end = mid - 1;
    
    return BinearySearch(start, end, value, times);
}

long long solution(int n, vector<int> times) {
    return BinearySearch(1, 10000000000000, n, times);
}