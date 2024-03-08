/*
#include <bits/stdc++.h>

using namespace std;

    map<int, int> big_2_index,index_2_big;
    set<int> all_points;
    int sparse_s[100001],sparse_e[100001],region_sum[200002],add[200002],sub[200002],dense_s[100001],dense_e[100001];
    bool is_passed[200002];

int main(){
    freopen("points11.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        sparse_s[i]=min(a,b);
        sparse_e[i]=max(a,b);
        all_points.insert(sparse_s[i]);
        all_points.insert(sparse_e[i]);
    }
    int num_of_unique=0;
    for(set<int>::iterator it=all_points.begin();it!=all_points.end();++it){
        //index_2_big[num_of_unique]=*it;
        big_2_index[*it]=num_of_unique++;
    }
    /*
    for(int i=0;i<n;i++){
        dense_s[i]=big_2_index[sparse_s[i]];
        dense_e[i]=big_2_index[sparse_e[i]];
        if(dense_s[i]>=num_of_unique or dense_s[i]<0)cout<<dense_s[i]<<" fuck "<<i<<endl;
        if(dense_e[i]>=num_of_unique or dense_e[i]<0)cout<<dense_e[i]<<" fuck "<<i<<endl;
    }

    int sub_count=0,add_count=0;
    for(int i=0;i<n;i++){
        sub[big_2_index[sparse_e[i]]]+=1;
        add[big_2_index[sparse_s[i]]]+=1;
    }
    /*
    for(int i=0;i<num_of_unique;i++){
        sub_count+=sub[i];
        add_count+=add[i];
    }

    //cout<<endl<<sub_count<<" "<<add_count<<endl;
    region_sum[0]=add[0];
    for(int i=1;i<num_of_unique;i++){
        region_sum[i]=region_sum[i-1]+add[i]-sub[i];
    }
    /*
    cout<<"("<<-INFINITY<<":"<<*all_points.begin()<<")="<<0<<endl;
    for(set<int>::iterator it=all_points.begin();it!=all_points.end();++it){
        cout<<"("<<*it<<":"<<*it<<")="<<region_sum[big_2_index[*it]]+sub[big_2_index[*it]]<<endl;
        if(++it==all_points.end())break;
        --it;
        cout<<"("<<*it;
        ++it;
        cout<<":"<<*it<<")=";
        --it;
        cout<<region_sum[big_2_index[*it]]<<endl;
    }
    cout<<"("<<*all_points.rbegin()<<":"<<INFINITY<<")="<<0<<endl;

    for(int i=0;i<m;i++){
        int query;
        cin>>query;
        if(all_points.lower_bound(query)==all_points.end() or query<*all_points.begin()){
            cout<<0<<" "; continue;
        }
        set<int>::iterator it=all_points.lower_bound(query);
        if(all_points.find(query)==all_points.end())--it;
        int query_index=big_2_index[*it];
        if(query==*it){
            cout<<region_sum[query_index]+sub[query_index]<<" ";
        }else{
            cout<<region_sum[query_index]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
/*
55 555
5 55

3 4
2 5
7 3
5 10
4 11 5 8

9 17
1 10
7 3
5 20
7 15
7 25
30 10
10 35
15 30
30 40
0 1 2 3 5 6 7 10 12 15 20 27 30 32 35 40 45

6 1
*/
#include <bits/stdc++.h>

using namespace std;

    map<int, int> big_2_index;
    set<int> all_points;
    int input[200002],region_sum[200002],add[200002],sub[200002];
    bool is_passed[200002];

int main(){
    freopen("points.11.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*2;i+=2){
        int a,b; cin>>a>>b;
        input[i]=min(a,b);
        input[i+1]=max(a,b);
        all_points.insert(input[i]);
        all_points.insert(input[i+1]);
    }
    int pos=0;
    for(set<int>::iterator it=all_points.begin();it!=all_points.end();++it){
        big_2_index[*it]=pos++;
    }
    for(int i=0;i<pos;i++){
        if(i%2!=0){
            sub[big_2_index[input[i]]]-=1;
        }else{
            add[big_2_index[input[i]]]+=1;
        }
    }
    for(set<int>::iterator it=all_points.begin();it!=all_points.end();++it){
        region_sum[big_2_index[*it]]=region_sum[big_2_index[*it]-1]+add[big_2_index[*it]]+sub[big_2_index[*it]];
        //cout<<add[big_2_index[*it]]<<" "<<sub[big_2_index[*it]]<<" "<<region_sum[big_2_index[*it]]<<endl;
    }

    for(int i=0;i<m;i++){
        int query;
        cin>>query;
        //cout<<*all_points.lower_bound(query)<<" "<<query<<endl;
        if(all_points.lower_bound(query)==all_points.end() or query<*all_points.begin()){
            cout<<0<<" "; continue;
        }
        set<int>::iterator it=all_points.lower_bound(query);
        if(all_points.find(query)==all_points.end())--it;
        //cout<<query<<" "<<*it<<" "<<*all_points.lower_bound(query)<<endl;
        int query_index=big_2_index[*it];
        if(query==*it){
            cout<<region_sum[query_index]-sub[query_index]<<" ";
        }else{
            cout<<region_sum[query_index]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
/*
1 3
1 3
1 3
3 5
3 5
3 5
3

1 3
-10 10
-100 100 0
*/
