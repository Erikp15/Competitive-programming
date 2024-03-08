#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 1000001
float a[MAXN], b[MAXN];
int M,N;

bool mycomp(float a,float b)
{ return a>b;  }

int main()
{  int i,j,k;
   scanf("%d %d",&M,&N);
   for(i=0;i<M;i++)scanf("%f",&a[i]);
   for(i=0;i<N;i++)scanf("%f",&b[i]);
   sort(a,a+M,mycomp);
   sort(b,b+N,mycomp);
   for(i=0,j=0;j<N;)
      if(a[i]>b[j])
      {
          if (i==j) printf("%.2f",a[i]);
          else printf(" %.2f",a[i]);
          i++;
      }
      else {i++;j++;}
   for(k=i;k<M;k++)
      if (k==j) printf("%.2f",a[k]);
      else printf(" %.2f",a[k]); 
   printf("\n");
}
