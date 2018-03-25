/*
先变成链再变成星星就可以，只有两种情况
*/
#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 1e6+5;
vector<int>g[N],p,gg[N];
vector<vector<int> >ans;
int size[N],n,f[N]={0},size_p[N]={0},V[N];
map<pair<int,int>,int>m;
vector<int>tmp;
vector<pair<int,int> >tmp1;
int dfs(int u,int fa)
{
	size[u]=1;
	for(auto &v:g[u]){if(v==fa)continue;size[u]+=dfs(v,u);}
	return size[u];
}
void dfs1(int u,int fa)
{
	for(auto &v:g[u]){if(v==fa)continue;dfs1(v,u);}
	int ma=n-size[u];
	for(auto &v:g[u]){if(v==fa)continue;ma=max(ma,size[v]);}
	if(ma*2<=n)p.pb(u);
}
void dfs2(int u,int fa)
{
	for(auto &v:g[u]){if(v==fa||2*size[v]==n)continue;dfs2(v,u);}
	int ff=fa;
	if(fa!=-1&&n-size[u]>size[u])for(auto &v:g[u]){if(v==fa)continue;
		if(!V[u])V[u]=f[v];
		ans.pb({ff,u,f[v]});
		m[{ff,u}]=m[{u,ff}]=0;m[{ff,f[v]}]=m[{f[v],ff}]=1;
		ff=(V[v]==0?v:V[v]);
	}f[u]=u;
}
int dfs4(int u,int fa)
{
	int t=u;
	for(auto &v:g[u]){if(v==fa)continue;t=dfs4(v,u);}
	if((int)g[u].size()==1)return u;
	if(fa!=-1) ans.pb({fa,u,t});
	return t;
}
int dfs5(int u,int fa)
{
	int si=1;
	for(auto &v:g[u]){if(v==fa)continue;si+=dfs5(v,u);}
	if(n%2==0){if(si==n/2){tmp.pb(fa),tmp.pb(u);}}
	else{if(si==n/2+1)tmp.pb(u);}
	return si;
}
int main()
{
	scanf("%d",&n);memset(V,0,sizeof(V));memset(f,0,sizeof(f));memset(size_p,0,sizeof(size_p));
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);g[u].pb(v);g[v].pb(u);}
	dfs(1,-1);dfs1(1,-1);
	for(int i=1;i<=n;i++)for(auto &v:g[i])m[{i,v}]=1;
	for(auto &t:p)dfs(t,-1),dfs2(t,-1);
	//for(auto &t:ans)printf("%d %d %d\n",t[0],t[1],t[2] );
	for(int i=1;i<=n;i++)g[i].clear();
	for(auto &t:m)if(t.se){g[t.fi.fi].pb(t.fi.se);size_p[t.fi.se]++;}
	dfs(1,-1);
	for(int i=1;i<=n;i++)if(size_p[i]>2)tmp.pb(i);
	if((int)tmp.size()==0){int tt;
		for(int i=1;i<=n;i++)if(size_p[i]==1){tt=i;break;}
		dfs5(tt,-1);
	}else{p.clear();
		dfs(1,-1);dfs1(1,-1);
		tmp.clear();for(auto &t:p)tmp.pb(t);
	}
	if((int)tmp.size()==1)for(auto &v:g[tmp[0]])tmp1.pb({v,tmp[0]});
	else{
		for(auto &v:g[tmp[0]])if(v!=tmp[1])tmp1.pb({v,tmp[0]});
		for(auto &v:g[tmp[1]])if(v!=tmp[0])tmp1.pb({v,tmp[1]});
	}
	for(auto &t:tmp1)dfs4(t.fi,t.se);
	printf("%d\n",(int)ans.size() );
	for(auto &t:ans)printf("%d %d %d\n",t[0],t[1],t[2] );
	return 0;
}
/*
10
1 4
1 5
1 6
1 2
2 10
10 3
3 7
3 8
3 9
*/
