#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll all_nums[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,seg_count=1;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>all_nums[i];
    }
    set<ll> segments_taken;
    segments_taken.insert(all_nums[0]);
    ll largest_note=1000001;
    for(ll i=1;i<n;i++){
        while(all_nums[i]<=largest_note and all_nums[i]>=all_nums[i-1] and i<n){
            segments_taken.insert(all_nums[i]);
            i++;
        }
        if(i!=n){
            seg_count++;
            segments_taken.insert(all_nums[i]);
            if(segments_taken.upper_bound(all_nums[i])!=segments_taken.end()){
                largest_note=*segments_taken.upper_bound(all_nums[i]);
            }else{
                largest_note=1000001;
            }
        }
    }
    cout<<seg_count;
    return 0;
}
/*
6
3 5 4 2 1 6
5
6
3 5 1 2 4 7

*/
