#include <iostream>

using namespace std;

bool is_prime(int a){
    for(int i=2;i<=a/2;i++){
        if(a%i==0)return false;
    }
    return true;
}

int main(){
    int n,prime_sum_count=0;
    cin>>n;
    for(int i=2;i<n-1;i++){
        if(is_prime(i) and is_prime(n-i))prime_sum_count++;
    }
    cout << prime_sum_count/2+prime_sum_count%2 << endl;
    return 0;
}
