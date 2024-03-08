#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct treap {
    int br,y;
    int num,ans;
    int le,ri;
    treap *l,*r;
    treap () {
        br=1; ans=1;
        l=r=NULL;
        }
};
treap *tr;
void recover (treap *&t) {
     t->br=1;
     t->ans=0;
     if ((t->l==NULL)&&(t->r==NULL)) {
        t->le=t->ri=t->num;
        t->ans=1;
        return ;
        }
     if (t->l==NULL) {
        t->le=t->num; t->ri=t->r->ri;
        t->br+=t->r->br;
        t->ans+=t->r->ans;
        if (t->num!=t->r->le) t->ans++;
        return ;
        }
     if (t->r==NULL) {
        t->le=t->l->le; t->ri=t->num;
        t->br+=t->l->br;
        t->ans+=t->l->ans;
        if (t->num!=t->l->ri) t->ans++;
        return ;
        }
     t->le=t->l->le; t->ri=t->r->ri;
     t->br+=t->l->br; t->br+=t->r->br;
     t->ans+=t->l->ans; t->ans+=t->r->ans;
     if ((t->l->ri==t->num)&&(t->num==t->r->le)) t->ans--;
     if ((t->l->ri!=t->num)&&(t->num!=t->r->le)) t->ans++;
}
void merge1 (treap *&t, treap *l, treap *r) {
     if ((l==NULL)||(r==NULL)) {
        if (l!=NULL) t=l;
        else t=r;
        return ;
        }
     if (l->y>r->y) t=l, merge1(t->r,l->r,r);
     else t=r, merge1(t->l,l,r->l);
     recover(t);
}
void split (treap *t, int x, treap *&l, treap *&r) {
     if (t==NULL) {
        l=r=NULL;
        return ;
        }
    int ind=0;
    if (t->l!=NULL) ind+=t->l->br;
    if (ind<x) l=t, split(t->r,x-ind-1,l->r,r), recover(l);
    else r=t, split(t->l,x,l,r->l), recover(r);
}
void insert1 (treap *&t, int x, int num, int y) {
     treap *l,*r,*ex;
     l=new treap; r=new treap; ex=new treap;
     ex->br=1;
     split(t,x,l,r);
     ex->num=ex->le=ex->ri=num;
     ex->ans=1; ex->y=y;
     merge1(t,l,ex);
     merge1(t,t,r);
}
void erase1 (treap *&t, int x) {
     treap *l,*r,*rl,*rr;
     l=new treap; r=new treap; rl=new treap; rr=new treap;
     split(t,x,l,r);
     split(r,1,rl,rr);
     merge1(t,l,rr);
}
void update (treap *&t, int x, int num) {
     treap *l,*r,*rl,*rr;
     l=new treap; r=new treap; rl=new treap; rr=new treap;
     split(t,x,l,r);
     split(r,1,rl,rr);
     rl->le=rl->ri=rl->num=num;
     merge1(t,l,rl);
     merge1(t,t,rr);
}
int rnds[200001];
int main () {
    int n,i,num,q,type,ind,col;
    scanf("%d",&n);
    srand(0);
    for (i=0; i<n+100000; i++) {
        rnds[i]=i;
        }
    random_shuffle(rnds,rnds+n+100000);
    for (i=0; i<n; i++) {
        scanf("%d",&num);
        insert1(tr,i,num,rnds[i]);
        }
    scanf("%d",&q);
    for (i=0; i<q; i++) {
        scanf("%d",&type);
        if (type==1) {
           scanf("%d",&ind);
           ind--;
           erase1(tr,ind);
           }
        else if (type==2) {
                scanf("%d%d",&ind,&col);
                ind--;
                insert1(tr,ind,col,rnds[n+i]);
                }
        else if (type==3) {
                scanf("%d%d",&ind,&col);
                ind--;
                update(tr,ind,col);
                }
        else printf("%d\n",tr->ans);
        }
    return 0;
}
