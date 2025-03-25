#include <string>
#include <vector>

using namespace std;

int solution(int N, int number) {
    int Answers[32001];
    for(int i = 0; i <= 32000; i++){
        if(i == N){
            Answers[N] = N;
        }
        else{
            Answers[i] = 0;
        }            
    } 
    
    vector<int> DP[9];
    
    int n = 1;
    while(true){
        if(n > 8) return -1;
        
        for(int i = 1; i <= n / 2; i++){
            for(int vectorNum1 : DP[i]){
                for(int vectorNum2 : DP[n - i]){
                    
                    int PlusNum = vectorNum1 + vectorNum2;
                    if(PlusNum == number) return n;
                    if(PlusNum <= 32000 && Answers[PlusNum] == 0){
                        Answers[PlusNum] = n;
                        DP[n].push_back(PlusNum);
                    } 
                    
                    int MinusNum = abs(vectorNum1 - vectorNum2);
                    if(MinusNum == number) return n;
                    if(MinusNum <= 32000 && Answers[MinusNum] == 0){
                        Answers[MinusNum] = n;
                        DP[n].push_back(MinusNum);
                    } 
                    
                    int MultNum = vectorNum1 * vectorNum2;
                    if(MultNum == number) return n;
                    if(MultNum <= 32000 && Answers[MultNum] == 0){
                        Answers[MultNum] = n;
                        DP[n].push_back(MultNum);
                    } 
                    
                    if(vectorNum2 != 0){
                        int DivideNum1 = vectorNum1 / vectorNum2;
                        if(DivideNum1 == number) return n;
                        if(DivideNum1 <= 32000 && Answers[DivideNum1] == 0){
                            Answers[DivideNum1] = n;
                            DP[n].push_back(DivideNum1);
                        }                         
                    }  
                    
                    if(vectorNum1 != 0){
                        int DivideNum2 = vectorNum2 / vectorNum1;
                        if(DivideNum2 == number) return n;
                        if(DivideNum2 <= 32000 && Answers[DivideNum2] == 0){
                            Answers[DivideNum2] = n;
                            DP[n].push_back(DivideNum2);
                        }                         
                    } 
                }
            }
        }
        
        int num = N;
        for(int i = 1; i < n; i++){
            int tempInt = N;
            for(int j = 0; j < i; j++){
                tempInt *= 10; 
            }
            num += tempInt;
        }        
        if(num == number) return n;
        DP[n].push_back(num);
        
        n++;
    }
    
    return Answers[number];
}