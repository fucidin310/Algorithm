#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
//티켓, 사용했는지
vector<pair<vector<string>, bool>> ticketList;
bool bIsAnswer = false;

void BackTracking(string curAirport, int n){      
    for(int i = 0; i < ticketList.size(); i++){
        if(ticketList[i].first[0] == curAirport && ticketList[i].second == false){
            answer.push_back(ticketList[i].first[1]);
            ticketList[i].second = true;
            BackTracking(ticketList[i].first[1], n + 1);
            if(bIsAnswer == true) return;
            ticketList[i].second = false;
            answer.pop_back();            
        }
    }
    
    if(n == ticketList.size()) bIsAnswer = true;
}

vector<string> solution(vector<vector<string>> tickets) {
    for(vector<string> ticket : tickets){
        ticketList.push_back(make_pair(ticket, false));        
    }    
    sort(ticketList.begin(), ticketList.end());
    answer.push_back("ICN");
    
    BackTracking("ICN", 0);
    
    return answer;
}