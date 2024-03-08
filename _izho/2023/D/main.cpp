#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e2+1;
ll b[Size];
ll k[Size];
pair<ll,ll> d[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    for(ll i=0;i<n;i++){
        cin>>k[i];
    }
    for(ll i=0;i<n;i++){
        cin>>d[i].first;
    }
    bool cringe=1;
    for(ll i=0;i<n;i++){
        cin>>d[i].second;
        if(d[i].second!=1){
            cringe=0;
        }
    }
    if(cringe){
        sort(b,b+n);
        sort(k,k+n);
        sort(d,d+n);
        reverse(b,b+n);
        reverse(k,k+n);
        reverse(d,d+n);
        ll pointer_b=0, pointer_k=0, pointer_d=0;
        ll ans=0;
        while(pointer_b<n and pointer_d<n and pointer_k<n){
            if(b[pointer_b]>d[pointer_d].first){
                pointer_b++;
                continue;
            }
            if(k[pointer_k]<d[pointer_d].first){
                pointer_d++;
                continue;
            }
            pointer_b++;
            pointer_d++;
            pointer_k++;
            ans++;
        }
        cout<<ans<<endl;
    }else{
        set<pair<ll,ll>> all_b, all_k;
        for(ll i=0;i<n;i++){
            all_b.insert({b[i],i});
            all_k.insert({k[i],i});
            swap(d[i].first, d[i].second);
        }
        ll ans=0;
        sort(d,d+n);
        reverse(d,d+n);
        for(ll i=0;i<n;i++){
            auto curr_b=all_b.upper_bound({d[i].second,1});
            if(!all_b.empty()){
                //cout<<"1:"<<(*curr_b).first<<endl;
                if(curr_b==all_b.end() or (*curr_b).first>d[i].second){
                    curr_b--;
                    //cout<<"2:"<<(*curr_b).first<<endl;
                    if(curr_b==all_b.end() or (*curr_b).first>d[i].second){
                        continue;
                    }
                }
            }else{
                continue;
            }
            auto curr_k=all_k.upper_bound({d[i].second,1});
            //cout<<"1:"<<(*curr_k).first<<endl;
            if(curr_k!=all_k.end()){
                ans+=d[i].first;
                all_k.erase(curr_k);
                all_b.erase(curr_b);
            }else{
                continue;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
4
2 2 1 8
4 10 10 4
2 3 10 8
6 5 3 5
19

3
1 4 10
1 2 4
1 3 4
2 3 2
4

3
1 9 10
200 200 200
1 2 4
4 3 2

3
1 4 10
1 2 4
2 2 2
2 3 2
*/
