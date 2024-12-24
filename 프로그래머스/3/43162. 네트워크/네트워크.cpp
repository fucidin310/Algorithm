#include <string>
#include <vector>

using namespace std;

int unionArr[200];

int Find(int num){
    if(unionArr[num] == num) return num;
    
    return unionArr[num] = Find(unionArr[num]);
}

bool Union(int num1, int num2){
    int unionNum1 = Find(num1);
    int unionNum2 = Find(num2);
    
    if(unionNum1 == unionNum2) return false;
    else{
        unionArr[Find(num1)] = unionArr[Find(num2)];
        return true;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = n;
    
    for(int i = 0; i < n; i++){
        unionArr[i] = i;
    }    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j] == 1){
                if(Union(i, j)) answer--;
            }
        }
    }
    
    return answer;
}