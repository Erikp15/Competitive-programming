#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dou;

class line{
public:
    dou a,b,c;
};
    dou xa1,ya1,xa2,ya2,xb1,yb1,xb2,yb2,ix,iy;
    line l1,l2;

    void calc_line(dou x1,dou y1,dou x2,dou y2,line& l){
        l.a=y1-y2;
        l.b=x2-x1;
        l.c=-l.a*x1-l.b*y1;
    }
    void calc_intersect(line line1,line line2){
        dou a1,b1,c1,a2,b2,c2,x,y;
        a1=line1.a*line2.a;
        b1=line1.b*line2.a;
        c1=line1.c*line2.a;
        a2=line2.a*line1.a;
        b2=line2.b*line1.a;
        c2=line2.c*line1.a;
        y=-(c1-c2)/(b1-b2);
        x=(-y*b1-c1)/a1;
        cout<<x<<" "<<y<<endl;
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>xa1>>ya1>>xa2>>ya2>>xb1>>yb1>>xb2>>yb2;
    calc_line(xa1,ya1,xa2,ya2,l1);
    calc_line(xb1,yb1,xb2,yb2,l2);
    cout<<l1.a<<" "<<l1.b<<" "<<l1.c<<endl;
    cout<<l2.a<<" " <<l2.b<<" "<<l2.c<<endl;
    calc_intersect(l1,l2);
    return 0;
}

