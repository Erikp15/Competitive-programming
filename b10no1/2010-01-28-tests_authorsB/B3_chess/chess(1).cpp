#include <cstdio>
#include <cctype>
#define BP(p,q) add(buf[i].x, buf[i].y, p, q)

struct {int y,x;} buf[2];
int A[10][10], i, j;

int add(int x, int y, int dx, int dy) {
  while (A[y+=dy][x+=dx]==0);
  return ++A[y][x]==2;
}

int main() {
  char s[10];
  for (i=0;i<10;i++) A[0][i]=A[9][i]=A[i][0]=A[i][9]=2;

  for ( i=0 ; scanf("%s",s)==1 ; i^=1)
    A[buf[i].y = s[1]-'0'][buf[i].x = tolower(s[0])-'a'+1] = 1;

  for ( i=0; i<2; A[buf[i].y][buf[i++].x]=2);

  for (i=j=0; i<2; i++)
    j += BP(-1,0)+BP(1,0)+BP(0,-1)+BP(0,1)+BP(-1,1)+BP(1,1)+BP(-1,-1)+BP(1,-1);
  printf("%d\n",j);
  return 0;
}
