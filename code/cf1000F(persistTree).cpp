#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long

const int N = 2e7+5;
const int maxn = 5e5+5;
vector<int>g[maxn];
int root[maxn],tot=0,L[N],R[N],a[maxn],m[maxn],Lvis[N],Rvis[N];
pair<int,int> T[N];
pair<int,int> MIN(pair<int,int> a,pair<int,int> b)
{
    if(a.fi<b.fi)return a;
    return b;
}
void build(int root,int l,int r)
{
    if(l==r) {T[root]={N,N};return ;}
    int mid = (l+r)/2;
    build(L[root]=++tot,l,mid);
    build(R[root]=++tot,mid+1,r);
    T[root]=MIN(T[L[root]],T[R[root]]);
}
void add(int id,int x,int root,int l,int r,int root1,pair<int,int> tmp)
{
    int mid = (l+r)/2;
    if(l==r){
        T[root]=tmp;
        return;
    }
    if(l<=id&&id<=mid){
        if(Lvis[root]==-1){
            Lvis[root]=1;L[root]=++tot;
            Rvis[root]=0;R[root]=R[root1];
        }else if(Lvis[root]==0){
            Lvis[root]=1;L[root]=++tot;
        }
        add(id,x,L[root],l,mid,L[root1],tmp);
    }else if(mid<id&&id<=r){
        if(Rvis[root]==-1){
            Rvis[root]=1;R[root]=++tot;
            Lvis[root]=0;L[root]=L[root1];
        }else if(Rvis[root]==0){
            Rvis[root]=1;R[root]=++tot;
        }
        add(id,x,R[root],mid+1,r,R[root1],tmp);
    }
    T[root]=MIN(T[L[root]],T[R[root]]);
}
pair<int,int> ask(int root,int l,int r,int L1,int R1)
{
    pair<int,int>l1,rr;
    l1=rr={N,N};
    if(L1<=l&&r<=R1)return T[root];
    /*if(l==r){
  //      printf("-- %d %d %d\n",root,T[root].fi,T[root].se);
        return T[root];
    }*/
    int mid = (l+r)/2;
    if(mid>=L1) l1=ask(L[root],l,mid,L1,R1);
    if(mid<R1) rr=ask(R[root],mid+1,r,L1,R1);
    return MIN(l1,rr);
}
int main()
{
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    memset(Lvis,-1,sizeof(Lvis));
    memset(Rvis,-1,sizeof(Rvis));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(g[a[i]].size()==0){m[i]=-1;}
        else {m[i]=g[a[i]].back();}
        g[a[i]].pb(i);
    }
    root[0]=0;
    build(root[0],1,5e5);
    for(int i=1;i<=n;i++){
        root[i]=++tot;
        add(i,m[i],root[i],1,n,root[i-1],{m[i],a[i]});
        if(m[i]!=-1)
            add(m[i],m[m[i]],root[i],1,n,root[i-1],{N,N});
    }
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int l,r;scanf("%d %d",&l,&r);
        pair<int,int> tmp=ask(root[r],1,n,l,r);
  //      printf("-- %d %d\n",tmp.fi,tmp.se );
        if(tmp.fi<l)printf("%d\n",tmp.se);
        else printf("0\n");
    }
    return 0;
}