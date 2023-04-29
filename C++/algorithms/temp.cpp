#include<iostream>

using namespace std;

long long calc(long long x, long long pot) {
    long long sum = 0;
    if (pot == 0) {
        return 1;
    }
    if (pot % 2) {
        sum += x * calc(x , pot - 1);
    } else {
        sum += calc(x , pot / 2) *  calc(x , pot / 2);
    }
    return sum;
}


int main(){
    cout << calc(5 , 13);
}
