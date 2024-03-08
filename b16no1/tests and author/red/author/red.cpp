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
			p1=b1; q1=a2;
		}
		else
		if (a==Min)
		{
			a2=i;
			if ((q1-p1)<(a2-b1)) p1=b1, q1=a2;
		}
			else
			if (a>Max) {
				Max=a;
				b1=b2=i;
				p1=a1; q1=b2;		
			}
			else
			if (a==Max) {
				b2=i;
				if ((q1-p1)<(b2-a1)) p1=a1, q1=b2;

			}
	}
	if (p1>q1)	swap(p1,q1);
	cout<<p1<<" "<<q1<<endl;
    return 0;
}

