//Implement Pow(x,n) | X raised to the power N

//Problem Statement: Implement the power function pow(x, n) , which calculates the x raised to n i.e. x^n.

#include<iostream>
using namespace std;
int main(){

    int x = 2;
    int n = 10;

    double ans = 1.0;
    int base = x;
    long long power = n;

    if(power < 0){
        power = power * (-1);
    }

    while(power != 0){
        if(power % 2 == 0){
            x = x * x;
            power = power/2;
        }
        else{
            ans = ans * x;
            power--;
        }
    }

    if(n<0){
        ans = (double)(1.0)/(double)(ans);
    }

    cout<<base<<" to the power of "<<n<<" is: "<<ans;


    return 0;
}