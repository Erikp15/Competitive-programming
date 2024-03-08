#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXM = 8;
const int MAX = 128;

int mr[MAXM] = { -1, -1, -1,  0, +1, +1, +1,  0 };
int mc[MAXM] = { -1,  0, +1, +1, +1,  0, -1, -1 };

int n, m;
int A[MAX][MAX];
bool used[MAX][MAX];

bool IsIn(int i, int j)
{ return i >= 0 && i <= n + 1 && j >= 0 && j <= m + 1; }

void Fill(int r, int c)
{
  used[r][c] = 1;
  
  for (int i = 0; i < MAXM; i++)
    if (IsIn(r + mr[i], c + mc[i]) && !used[r + mr[i]][c + mc[i]] && A[r + mr[i]][c + mc[i]] == 1)
      Fill(r + mr[i], c + mc[i]);
}

int main()
{
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &A[i][j]);      
  
  for (int j = 0; j <= m + 1; j++) { A[0][j] = 1; A[n + 1][j] = 1; }
  for (int i = 0; i <= n + 1; i++) { A[i][0] = 1; A[i][m + 1] = 1; }
  
  int res = 0;
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++)
      if (!used[i][j] && A[i][j] == 1)
        {
          Fill(i, j);
          res++;
        }
  
  printf("%d\n", res - 1);
  
  return 0;
}
