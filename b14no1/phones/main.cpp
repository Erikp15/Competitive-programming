/*
#include <bits/stdc++.h>

using namespace std;

    int all_payments[51201];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("phones10.in","r",stdin);
    freopen("output.txt","w",stdout);
    long long n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        float a;
        cin>>a;
        int b=a*128+0.5;
        all_payments[b]++;
    }
    for(int i=0;i<n;i++){
        float a;
        cin>>a;
        int b=a*128+0.5;
        all_payments[b]--;
    }
    for(int i=40000;i>=0;i--){
        if(all_payments[i]>0){
            float a=(i/128.00);
            for(int j=0;j<all_payments[i];j++){
                cout<<setprecision(2)<<fixed<<a<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 1000001
float a[MAXN], b[MAXN];
int M,N;

bool mycomp(float a,float b)
{ return a>b;  }

int main(){
    freopen("phones10.in","r",stdin);
    freopen("output.txt","w",stdout);
   int i,j,k;
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

