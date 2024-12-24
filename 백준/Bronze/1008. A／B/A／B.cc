#include <iostream>
using namespace std;

int main(){
    cout<<fixed;
    cout.precision(9);
    
    double a, b;
    cin >> a >> b;
    cout << a / b;
}