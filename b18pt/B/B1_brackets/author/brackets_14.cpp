#include <iostream>
using namespace std;

const int N=1010;
bool p[N];
int n,k;

int mod=1001027;

long long int f(int i, int j)
{
  if(i==1)
  { if(j==1) return 1;
    return 0;
  }


  if(p[i])
  {
   if(j==0) return 0;
   return f(i-1,j-1);
  }
  else
  {
   if(j==0) return f(i-1,j+1);
   return (f(i-1,j+1)+f(i-1,j-1))%mod;
  }
}


int main()
{
  cin >> n >> k;
  for(int i=1;i<=k;i++)
   {
      int v; cin >> v;
      p[v]=1;
   }

  long long int r=f(2*n,0);
  cout << r << endl;

}


