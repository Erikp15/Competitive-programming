#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a_count,b_count,c_count;
    cin>>a_count>>b_count>>c_count;
    ll seats=a_count+b_count+c_count, seats_for_a[10001];
    for(ll i=0;i<a_count;i++){
        cin>>seats_for_a[i];
        seats_for_a[i]--;
        if(i!=0){
            if((seats_for_a[i]-seats_for_a[i-1]-1)%2==0){
                a_count--;
            }
        }
    }
    if(a_count>b_count+c_count+1 or b_count>a_count+c_count+1 or c_count>b_count+a_count+1){
        cout<<-1<<endl;
        return 0;
    }
    string res;
    ll a_used=0,b_used=0,c_used=0;
     for(ll i=0;i<seats;i++){
        if(i==seats_for_a[a_used]){
            a_used++;
            a_count--;
            res=res+'A';
            continue;
        }
        if(a_count<0)a_count=0;
        if(b_count>0){
            if(i+1==seats_for_a[a_used]){
                if(b_count+a_count>c_count){
                    b_used++;
                    b_count--;
                    res=res+'B';
                    continue;
                }else{
                    if(c_count>0){
                        c_used++;
                        c_count--;
                        res=res+'C';
                    }else{
                        break;
                    }
                }
            }else{
                if(b_count+a_count>=c_count){
                    b_used++;
                    b_count--;
                    res=res+'B';
                    continue;
                }else{
                    if(c_count>0){
                        c_used++;
                        c_count--;
                        res=res+'C';
                    }else{
                        break;
                    }
                }
            }
        }else{
            if(c_count>0){
                c_used++;
                c_count--;
                res=res+'C';
            }else{
                break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
