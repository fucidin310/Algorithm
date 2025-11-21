#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> myMap;
    
    for(vector<string>& s : clothes){
        myMap[s[1]]++;
    }
    
    int answer = 1;
    
    for(auto& s : myMap){
        answer *= (s.second + 1);
    }
    
    return answer - 1;
}