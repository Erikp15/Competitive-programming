#include <bits/stdc++.h>

using namespace std;

typedef int ll;

    ll arr[10001];
    //vector<ll> break_points;
    ll pal_count_even[10001],pal_count_odd[10001];

void manacher(ll array_size){
    ll l_even=0,r_even=0;
    for(ll i=0;i<array_size;i++){
        ll k=(i>=r_even) ? 0 : min(pal_count_even[l_even+r_even-i-1],r_even-i+1);
        while(i-k+1>=0 and i+k+1<array_size and arr[i-k]==arr[i+k+1])k++;
        pal_count_even[i]=k--;
        if(i+k>=r_even){
            l_even=i-k;
            r_even=i+k+1;
        }
    }
    ll l_odd=0,r_odd=0;
    for(ll i=0;i<array_size;i++){
        ll k=(i>r_odd) ? 1 : min(pal_count_odd[l_odd+r_odd-i],r_odd-i);
        while(i-k>=0 and i+k<array_size and arr[i-k]==arr[i+k])k++;
        pal_count_odd[i]=k--;
        if(i+k>r_odd){
            l_odd=i-k;
            r_odd=i+k;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,pal_count[10002],prevous[10002],group_count=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    for(ll i=0;i<=n;i++){
        pal_count[i]=n;
    }
    manacher(n);
    pal_count[0]=0;
    prevous[0]=-1;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=i;j++){
            ll curr_index=(i+j)/2;
            if((i+j)%2==1){
                if(pal_count_odd[curr_index]>curr_index-j){
                    if(pal_count[i]>pal_count[j]+1){
                        prevous[i]=j;
                        pal_count[i]=pal_count[j]+1;
                    }
                }
            }else{
                if(pal_count_even[curr_index-1]>=curr_index-j){
                    if(pal_count[i]>pal_count[j]+1){
                        prevous[i]=j;
                        pal_count[i]=pal_count[j]+1;
                    }
                }
            }
        }
    }

    for(ll i=prevous[n];i!=-1;i=prevous[i]){
        group_count++;
        //break_points.push_back(i);
    }
/*
    cout<<break_points.size()<<endl;
    for(ll i=break_points.size()-2;i>=0;i--){
        cout<<break_points[i]<<" ";
    }
    */
    cout<<group_count<<endl;
    return 0;
}
/*
7
1 0 0 1 1 0 0
*/
