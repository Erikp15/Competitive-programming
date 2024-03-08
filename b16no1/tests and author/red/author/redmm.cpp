#include<cstdio>

using namespace std;

int a[100001];
int main()
{
    
    int n;
    scanf("%d",&n);
    int mini=1000001, maxi=-1;
    int a1, a2, b1, b2;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]==mini) a2=i;
        if(a[i]<mini)
        {
            a1=a2=i;
            mini=a[i];
            
        }
        if(a[i]==maxi) b2=i;
        if(a[i]>maxi)
        {
            b1=b2=i;
            maxi=a[i];
        }
    }
  //  printf("%d %d %d %d\n",a1,a2,b1,b2);
    int left, right;
    if(a1<=a2 && a2<=b1 && b1<=b2)
    {
        left=a1; right=b2;
    }
    if(a1<=b1 && b1<=a2 && a2<=b2)
    {
        left=a1; right=b2;
    }
    if(b1<=a1 && a1<=b2 && b2<=a2)
    {
        left=b1; right=a2;
    }
    if(b1<=b2 && b2<=a1 && a1<=a2)
    {
        left=b1; right=a2;
    }
    if(a1<=b1 && b1<=b2 && b2<=a2)
    {
        if(b2-a1>=a2-b1)
        {
            left=a1; right=b2;
        }
        else
        {
            left=b1;right=a2;
        }
    }
    if(b1<=a1 && a1<=a2 && a2<=b2)
    {
        if(a2-b1>=b2-a1)
        {
            left=b1; right=a2;
        }
        else
        {
            left=a1;right=b2;
        }
    }
    printf("%d %d\n",left,right);
    return 0;
}