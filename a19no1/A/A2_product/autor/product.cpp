#include<iostream>
using namespace std;

const int N=1000001;
int a[N+1];
int n;


int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

	int L = 1;
	int R = n;
	long long int s = 0;

	while (L < R)
	{
      s = max(s, ((long long int)(R-L))*min(a[L],a[R]));
      if (a[L] < a[R]) L++; else R--;
	}

	cout << s << endl;
}

