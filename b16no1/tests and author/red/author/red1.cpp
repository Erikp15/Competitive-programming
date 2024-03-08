#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a, a1,a2,b1,b2,p1,q1,i,n,Min,Max;
    cin>>n>>a;
    Min=Max=a;
    a1=a2=b1=b2=p1=q1=1;
	for (i=2; i<=n;i++) {
    	cin >> a;
    	if (a<Min) {
    		Min=a;
    		a1=a2=i;
		}
		else
		if (a==Min)
		{
			a2=i;
		}
			else
			if (a>Max) {
				Max=a;
				b1=b2=i;
			}
			else
			if (a==Max) {
				b2=i;
			}
	}
	p1=1; q1=1;
	if (a1<b1) 
		if ((b1-a1) > (q1-p1)) p1=a1, q1=b1;
	if (a1<b2) 
		if ((b2-a1) > (q1-p1)) p1=a1, q1=b2;
	if (b1<a1) 
		if ((a1-b1) > (q1-p1)) p1=b1, q1=a1;
	if (b1<a2) 
		if ((a2-b1) > (q1-p1)) p1=b1, q1=a2;

	cout<<p1<<" "<<q1<<endl;
	
    return 0;
}

