#include<iostream>
#include<algorithm>
using namespace std;

int n;
const int M=1001;
pair<int,int> seg[M];

int main()
{
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> seg[i].first >> seg[i].second;
  seg[n].first=10000; seg[n].second=10001;
  sort(seg, seg+n+1);
  int left=seg[0].first, right=seg[0].second, max=0, cnt=0;
  for(int i=1; i<=n; i++)
  {
      if(seg[i].first<=right && right < seg[i].second)
        right = seg[i].second;
      else if(right < seg[i].first)
            {
                cnt++;
                int l=right-left;
                if (l>max) max=l;
                left=seg[i].first;
                right=seg[i].second;
            }
  }
  cout << cnt << " " << max << "\n";

  return 0;


}

