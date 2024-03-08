#include <stdio.h>
#define MAXN 1001
#define MAXK 33
#define INF 2000000000
int r[MAXN][33],g[MAXN][MAXN];
int N,K;
int P[MAXN];
void Prim()
{  int used[MAXN]={0},near[MAXN];
   int i,j,k,minc,minv;
   P[1]=0; used[1]=1;
   for(i=1;i<=N;i++) near[i]=1;
   for(i=1;i<N;i++)
   {  minc=INF;minv=0;
      for(j=1;j<=N;j++)
         if(!used[j]&&g[j][near[j]]<minc)
         {  minc=g[j][near[j]];minv=j; }
      P[minv]=near[minv];used[minv]=1;
      for(j=1;j<=N;j++)
         if(!used[j]&&g[j][near[j]]>g[j][minv])
           near[j]=minv;
   }
}

int main()
{
    int i,j,m,f,s,flag;
    int t,T;
    scanf("%d %d",&N,&K);
    for(i=1;i<=N;i++)
    {
       scanf("%d",&m);
       g[i][0]=m;
       for(j=1;j<=m;j++) scanf("%d",&r[i][j]);
       g[i][j]=0;
       if(i!=1)
       {
          for(m=1;m<i;m++)
          {
             f=s=1;flag=1;
             while(f<=g[m][0]&&s<=g[i][0])
             {  if(r[m][f]<r[i][s]) f++;
                else if(r[m][f]>r[i][s]) s++;
                else {g[m][i]=g[i][m]=r[m][f];flag=0;break;}
             }
             if(flag)g[m][i]=g[i][m]=K+1;

          }
       }
    }
//for(i=1;i<=N;i++)
//   {for(j=1;j<=N;j++) printf("%10d ",g[i][j]);printf("\n");}
    Prim();
    s=0;
    for(i=2;i<=N;i++)
    {  //printf("%d %d %d\n",i,P[i],g[i][P[i]]);
       s+=g[i][P[i]];
    }
    printf("%d\n",s);
    return 0;
}
