#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1;

ll trees[Size],lis[Size],lds[Size],lis_num[Size],lds_num[Size],best[Size],maxv=0;

void b_search(ll l,ll r,ll v){
    ll mid=(l+r)/2;
    if(v==best[mid])return;
    if((v>best[mid] and v<best[mid+1]) or (l==r)){
        if(mid==maxv){
            maxv++;
        }
        best[mid+1]=v;
    }else{
        if(v>best[mid]){
            b_search(mid+1,r,v);
        }else{
            b_search(l,mid,v);
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>trees[i];
        best[i]=1e18;
    }
    best[0]=0;
    for(ll i=1;i<=n;i++){
        b_search(0,i,trees[i-1]);
        lis[i]=maxv;
        lis_num[i]=best[maxv];
    }
    reverse(trees,trees+n);
    for(ll i=1;i<n;i++){
        best[i]=1e18;
    }
    maxv=0;
    for(ll i=1;i<=n;i++){
        b_search(0,i,trees[i-1]);
        lds[i]=maxv;
        lds_num[i]=best[maxv];
    }
    ll ans=0;
    for(ll i=0;i<=n;i++){
        ll comp=lis[i]+lds[n-i];
        ans=max(ans,comp);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll all_trees[100001];
    ll best_so_far[100001],best_so_far_reverse[100001];

int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>all_trees[i];
    }
    for(ll i=0;i<100001;i++){
        best_so_far[i]=100001;
    }
    best_so_far[0]=all_trees[0];
    best_so_far_reverse[0]=all_trees[0];
    ll best_length=0;
    for(ll i=1;i<n;i++){
        ll start_pivot=0,end_pivot=i,middle_pivot=i/2;
        while(!(all_trees[i]==best_so_far[middle_pivot] or all_trees[i]==best_so_far[middle_pivot-1])){
            if(all_trees[i]>best_so_far[middle_pivot]){
                if(all_trees[i]<best_so_far[middle_pivot+1]){
                    if(best_so_far[middle_pivot+1]==100001)best_length++;
                    best_so_far[middle_pivot+1]=all_trees[i];
                    break;
                }
                start_pivot=middle_pivot;
                middle_pivot=(end_pivot-start_pivot)/2+start_pivot;
            }else{
                if(all_trees[i]>best_so_far[middle_pivot-1]){
                    if(best_so_far[middle_pivot]==100001)best_length++;
                    best_so_far[middle_pivot]=all_trees[i];
                    break;
                }
                end_pivot=middle_pivot;
                middle_pivot=(end_pivot-start_pivot)/2;
            }
        }
        start_pivot=0; end_pivot=i; middle_pivot=i/2;
        while(!(all_trees[i]==best_so_far_reverse[middle_pivot] or all_trees[i]==best_so_far_reverse[middle_pivot-1])){
            if(all_trees[i]>best_so_far_reverse[middle_pivot]){
                if(middle_pivot==0){
                    best_so_far_reverse[middle_pivot]=all_trees[i];
                    break;
                }
                if(all_trees[i]<best_so_far_reverse[middle_pivot-1]){
                    best_so_far_reverse[middle_pivot]=all_trees[i];
                    break;
                }
                end_pivot=middle_pivot;
                middle_pivot=(end_pivot-start_pivot)/2;
            }else{
                if(all_trees[i]>best_so_far_reverse[middle_pivot+1]){
                    best_so_far_reverse[middle_pivot+1]=all_trees[i];
                    break;
                }
                start_pivot=middle_pivot;
                middle_pivot=(end_pivot-start_pivot)/2+start_pivot;
            }
        }
        ll j=best_length;
        while(best_so_far[best_length]>best_so_far_reverse[j]){
            best_so_far_reverse[j]=best_so_far[best_length];
            j--;
        }
    }
    for(ll i=n;i>=0;i--){
        if(best_so_far_reverse[i]!=0){
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}

/*
10
10 9 8 7 6 5 4 3 2 1
1

10
1 2 3 4 5 6 7 8 9 10
10

10
1 10 2 9 3 8 4 7 5 6
6

10
1 6 7 8 3 4 5 10 9 2
7

10
8 3 6 1 10 3 2 5 4 4
5
*/
