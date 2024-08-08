#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll Size=9, trial_count=1e3;

ll a[Size];
ld dice_powers[trial_count][Size][41];
ll n,m,k;
ld p,x,y;
mt19937 generator;
uniform_real_distribution<ld> distribution(0.0,1.0);

void simulate_dice(){
    for(ll i=0;i<trial_count;i++){
        ld sum=0;
        //cout<<probabilities[i]<<" ";
        for(ll j=0;j<n;j++){
            dice_powers[i][j][0]=1;
            dice_powers[i][j][1]=distribution(generator);
            sum+=dice_powers[i][j][1];
        }
        for(ll j=0;j<n;j++){
            dice_powers[i][j][1]=dice_powers[i][j][1]/sum;
            for(ll k=2;k<=m;k++){
                dice_powers[i][j][k]=dice_powers[i][j][k-1]*dice_powers[i][j][1];
                //cout<<dice_powers[i][j][k]<<" ";
            }
            //cout<<endl;
        }
        //cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>p>>x>>y>>k;
    ld avg=0;
    simulate_dice();
    for(ll i=0;i<k;i++){
        ld likelyhood=powf((ld)1/n,m);
        for(ll j=0;j<n;j++){
            cin>>a[j];
        }
        ld inverse_likelyhood=0;
        for(ll j=0;j<trial_count;j++){
            ld curr_prob=1;
            for(ll k=0;k<n;k++){
                curr_prob*=dice_powers[j][k][a[k]];
            }
            inverse_likelyhood+=curr_prob;
        }
        inverse_likelyhood/=trial_count;
        //cout<<likelyhood<<" inv: "<<inverse_likelyhood<<" ratio: "<<likelyhood/inverse_likelyhood<<endl;
        ld bayesian_outcome=(likelyhood*p)/(likelyhood*p+inverse_likelyhood*(1-p));
        //cout<<bayesian_outcome<<" "<<(1-bayesian_outcome)*y<<endl;
        //cout<<(1-bayesian_outcome)<<" "<<bayesian_outcome*x<<endl;
        if((1-bayesian_outcome)*y<bayesian_outcome*x){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
/*
3 15 0.6 0.35 0.65
4
4 7 4
5 5 5
9 5 1
3 6 6

3 15 0.5 0.5 0.5
4
4 7 4
5 5 5
9 5 1
3 6 6

2 20 0.5 0.5 0.5
1
10 10

3 15 0.5 0.5 0.5
1
5 5 5

3 18 0.5 0.5 0.5
1
6 6 6

3 21 0.5 0.5 0.5
1
7 7 7

4 24 0.5 0.5 0.5
1
6 6 6 6

6 36 0.5 0.5 0.5
2
6 6 6 6 6 6
5 7 6 5 5 8
*/
