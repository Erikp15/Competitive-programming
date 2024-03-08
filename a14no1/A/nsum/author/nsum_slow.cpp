#include <iostream>
using namespace std;

int main(){
  long long n,s;
  long long rc=1;  
  long long i,j;
  cin >> n;
  for (i=1;i<=n/2;i++)
  {
    s=i;
    j=i+1;
    while (s+j<n)  
    {
      s=s+j;
      j++;  
    }
    if ((s+j)==n) rc++;
  }
  cout << rc << endl;
  return 0;

}