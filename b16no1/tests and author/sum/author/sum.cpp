#include<iostream>
using namespace std;

long long k[3005];

int main()
{
    int n;
    cin >> n;
    k[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(i%2) k[i]=k[i-1];
        else k[i]=k[i-1]+k[i/2]; 
    }
    cout << k[n] << endl; 
    return 0;
}