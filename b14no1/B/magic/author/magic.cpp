#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[9], s1, s2, s3, s4, s5, s6, s7, s8, br=0;
    for(int i=0; i<9; i++)
      cin >> a[i];
    sort(a,a+9);
    do
    {
        s1=a[0]+a[1]+a[2];
        s2=a[3]+a[4]+a[5];
        s3=a[6]+a[7]+a[8];
        s4=a[0]+a[3]+a[6];
        s5=a[1]+a[4]+a[7];
        s6=a[2]+a[5]+a[8];
        s7=a[0]+a[4]+a[8];
        s8=a[2]+a[4]+a[6];
        if(s1==s2 && s2==s3 && s3==s4 && s4==s5 && s5==s6 && s6==s7 && s7==s8) br++;
        
    }while(next_permutation(a,a+9));
    cout << br << endl;
    return 0;
}