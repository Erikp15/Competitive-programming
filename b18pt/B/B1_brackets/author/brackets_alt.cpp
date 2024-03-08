#include <iostream>
using namespace std;

const int N=1010;
bool p[2*N];
long long int d[2*N][2*N];
int n,k;

int mod=1001027;

int main()
{
  cin >> n >> k;
  for(int i=1;i<=k;i++)
   {
      int v; cin >> v;
      p[v]=1;
   }

  d[0][0] = 1;
  for (int i = 1; i <= 2*n; i++)
  for (int j = 0; j <= 2*n; j++)
   if (p[i])
    {
     if (j != 0) d[i][j] = d[i - 1][j - 1];
     else d[i][j] = 0;
    }
    else
    {
     if (j != 0)
        d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1])%mod;
     else d[i][j] = d[i - 1][j + 1];
    }

  cout << d[2*n][0] << endl;
}


