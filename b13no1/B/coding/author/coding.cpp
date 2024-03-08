///Task: coding
///Author: Mladen Manev

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s, t, a[10]={"11","100","101","110","111","1000","1001","1010","1011","1100"};
    int br=0, x, c;
    cin >> s;
    if(s=="11")
    {
        cout << 0 << endl;
        return 0;
    } 
    for(int i=1; i<=90000; i++)
    {
        t="";
        x=i;
        while(x!=0)
        {
            c = x%10;
            x = x/10;
            t = a[c]+t;
        }
        if(t==s)
        {
            cout << i << endl;
            br++;
        }
    }
    if(br==0) cout << -1 << endl;
    return 0;
}
