#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> mySet;
    
    for(int num : nums) mySet.insert(num);
    
    int answer = min(mySet.size(), nums.size() / 2);
        
    return answer;
}