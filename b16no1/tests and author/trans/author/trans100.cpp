#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=100002;

int a[2*MAXN];
int b[MAXN];

int main()
{
    int p, m;
    scanf("%d%d",&p,&m);
    int x, y;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&x,&y);
        a[2*i-1]=x;
        a[2*i]=y;
    }
    int k;
    scanf("%d",&k);
    sort(a+1,a+2*m+1);
    a[0]=-1;a[2*m+1]=-1;
    int br=0, ans=0;
    for(int i=1; i<=2*m+1; i++)
    {
        if(a[i]==a[i-1]) br++;
        else
        {
           if (br>=k)
           {
               b[ans]=a[i-1];
               ans++;
           }
           br=1; 
        }
    }
    printf("%d\n",ans);
    if (ans==0) return 0;
    printf("%d",b[0]);
    for(int i=1; i<ans; i++)
      printf(" %d",b[i]);
    printf("\n");
    return 0;
}