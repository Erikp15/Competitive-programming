///Task: tribonacci
///Author: Vladimir Vladimirov

#include <iostream>
using namespace std;

int a, b, c, d;

int main()
{
    int p,sol; 
    cin >> p;
    
    a = b = 0; c = 1;                                  
    
    for(int i=3; ; i++)
    {
        d = (a + b + c) % p;      
        a = b; b = c; c = d;
              
        if ( a==0 && b==0 && c==1 )     
        {
            sol = i-2;
            break;
        }
    }
    
    cout << sol << endl;
    
    return 0;
}