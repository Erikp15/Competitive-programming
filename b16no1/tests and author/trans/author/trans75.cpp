#include <iostream>
#include <algorithm>
using namespace std;


int n,m,k,vr[10001], br;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	int p,q;
        cin>>p>>q;
        vr[p]++; vr[q]++;
	}
	cin>>k;
    for (int i = 1; i <= n; i++)
    	if (vr[i]>=k) 
			br++;
    cout<<br<<endl;
    if (br==0) return 0;
    int i=1;
    while(vr[i]<k) i++;
    cout << i++;
    for (; i <= n; i++)
    	if (vr[i]>=k)
    		cout << " " << i;
    cout<<endl;	
    return 0;
}
