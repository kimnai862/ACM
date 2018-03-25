/*
奇数环说明没有不相交的环，dfs找最值dp预处理
二分询问答案
*/
#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define lson root<<1,l,(r+l)/2
#define rson root<<1|1,(r+l)/2+1,r
const int N = 4e6+5;
const ll INF = 1e18;
vector<int>g[N];
int vis[N],dep[N],fa[N];
ll R[N],sum[N];
void dfs(int u)
{
	vis[u]=1;
	for(auto &v:g[u]){
		if(vis[v]&&dep[v]<dep[u]&&v!=fa[u]){
			int mx=u,mi=u,x=u;
			while(x!=v){
				x=fa[x];
				mi=min(x,mi);mx=max(x,mx);
			}R[mi]=min(R[mi],mx*1LL);
		}
		if(vis[v])continue;
		fa[v]=u;dep[v]=dep[u]+1;
		dfs(v);
	}
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	for(int i=1;i<=n;i++)R[i]=n+1;
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=n-1;i;i--)R[i]=min(R[i],R[i+1]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+R[i]-i;
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		int x=upper_bound(R+l,R+r+1,r)-R;
		printf("%lld\n",sum[x-1]-sum[l-1]+1LL*(r-x+1)*(r-x+2)/2);
	}
    return 0;
}