#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
    int p, m;
    scanf("%d%d",&p,&m);
    int x;
    vector<int> a;
    vector<int> b;
    a.push_back(-1);
    for(int i=0; i<2*m; i++)
    {
        scanf("%d",&x);
        a.push_back(x);
    }
    int k;
    scanf("%d",&k);
    sort(a.begin(),a.end());
    a.push_back(-1);
    int br=0, ans;
    for(int i=1; i<=2*m+1; i++)
    {
        if(a[i]==a[i-1]) br++;
        else
        {
           if (br>=k)
               b.push_back(a[i-1]);
           br=1; 
        }
    }
    ans=b.size();
    printf("%d\n",ans);
    if (ans==0) return 0;
    printf("%d",b[0]);
    for(int i=1; i<ans; i++)
      printf(" %d",b[i]);
    printf("\n");
    return 0;
}