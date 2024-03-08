#include <iostream>
using namespace std;

int main(){
  long long n,br=0;
  long long r;
  cin >> n;
  r=1;
  while (r*r<=n)
  {
     if (n%r==0) 
     {    
       if (r%2 !=0) br++;
       if (((n/r)%2!=0) && (r!=(n/r))) br++;  
     }
     r++;           
  }
  cout << br << endl;
}