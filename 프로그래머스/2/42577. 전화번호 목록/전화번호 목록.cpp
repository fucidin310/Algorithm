#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {    
    unordered_set<string> mySet;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(string phoneNum : phone_book){
        string tmp;
        for(char num : phoneNum){
            tmp += num;
            if(mySet.find(tmp) != mySet.end()) return false;
        }
        
        mySet.insert(phoneNum);
    }  
        
    return true;
}