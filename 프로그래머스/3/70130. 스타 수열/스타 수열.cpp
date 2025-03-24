#include <string>
#include <vector>
#include <map>

int solution(std::vector<int> a) {
    int answer = 0;
    
    std::map<int, int> myMap;
    std::map<int, int> lastNumMemoryMap;
    
    for(int i = 0; i < a.size() - 1; i++){
        if(a[i] == a[i + 1]) continue;
        
        if(lastNumMemoryMap.find(a[i]) == lastNumMemoryMap.end() ||
           lastNumMemoryMap[a[i]] != i){
            myMap[a[i]]++;
            lastNumMemoryMap[a[i]] = i + 1;
            answer = std::max(answer, myMap[a[i]]);
        }
        
        if(lastNumMemoryMap.find(a[i + 1]) == lastNumMemoryMap.end() ||
           lastNumMemoryMap[a[i + 1]] != i){
            myMap[a[i + 1]]++;
            lastNumMemoryMap[a[i + 1]] = i + 1;
            answer = std::max(answer, myMap[a[i + 1]]);
        }        
    }
    
    return answer * 2;
}