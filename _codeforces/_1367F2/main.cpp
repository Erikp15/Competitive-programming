#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=3001;
    ll a[Size];
    ll sorted_a[Size];
    map<ll,ll> s_2_i,i_2_ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll m=0;m<t;m++){
        ll n,ans=0;
        cin>>n;
        for(ll i=0;i<Size;i++){
            a[i]=-1;
            sorted_a[i]=-1;
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            sorted_a[i]=a[i]*1000000;
            sorted_a[i]+=i;
        }
        sort(sorted_a,sorted_a+n);
        for(ll i=0;i<n;i++){
            s_2_i[sorted_a[i]]=i;
            i_2_ans[i]=0;
        }
        for(ll i=0;i<n;i++){
            if(s_2_i[a[i]*1000000+i]-1>=0){
                i_2_ans[i]=i_2_ans[sorted_a[s_2_i[a[i]*1000000+i]-1]%1000000]+1;
                cout<<sorted_a[s_2_i[a[i]*1000000+i]-1]%1000000<<" ";
            }else{
                i_2_ans[i]=1;
                cout<<-1<<" ";
            }
            ans=max(ans,i_2_ans[i]);
        }
        cout<<endl<<n-ans<<"\n";
    }
    return 0;
}
/*
2
10
3 7 1 6 2 9 5 4 0 8
10
8 2 3 6 0 9 4 7 5 1
8
6

1
5
4 7 2 2 9
2

1
20
16 15 1 10 0 14 0 10 3 9 2 5 4 5 17 9 10 20 0 9
16
*/
