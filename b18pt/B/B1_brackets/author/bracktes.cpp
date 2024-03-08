#include <iostream>
#include <cstring>
using namespace std;

const int N=1010;
bool p[2*N];
int n,k;

int mod=1001027;

long long d[2*N][2*N];

long long int f(int i, int j)
{

  if(d[i][j]>-1) return d[i][j];

  if(i==1)
  { if(j==1) {d[i][j]=1; return 1;}
    d[i][j]=0; return 0;
  }


  if(p[i])
  {
   if(j==0) {d[i][j]=0; return 0;}
   d[i][j]=f(i-1,j-1); return d[i][j];
  }
  else
  {
   if(j==0) {d[i][j]=f(i-1,j+1); return d[i][j];}
   d[i][j]=(f(i-1,j+1)+f(i-1,j-1))%mod; return d[i][j];
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

  memset(d,-1,sizeof d);

  long long int r=f(2*n,0);
  cout << r << endl;

}


