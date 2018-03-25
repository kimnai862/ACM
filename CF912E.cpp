/*
分成两个集合二分答案
*/
#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define lson root<<1,l,(l+r)/2
#define rson root<<1|1,(l+r)/2+1,r
const int N = 1e5+5;
const ll INF = 1e18;
const ll p = 1e9+7;
int n;
vector<ll>v,v1,a,b;
void dfs (ll sum,int id)
{
	if(id>=(int)v.size()){return ;}
	if(sum<=1e18/v[id]){a.pb(sum*v[id]);dfs(sum*v[id],id);dfs(sum,id+1);}
	else dfs(sum,id+1);
}
void dfs1 (ll sum,int id)
{
	if(id>=(int)v1.size()){return ;}
	if(sum<=1e18/v1[id]){b.pb(sum*v1[id]);dfs1(sum*v1[id],id);dfs1(sum,id+1);}
	else dfs1(sum,id+1);
}
int lena,lenb;
ll fun(ll x)
{
	ll ans=0;
	ll l=0,r=lenb-1;
	while(l<lena)
	{
		while(r>=0&&a[l]>x/b[r])r--;
		if(r<0){break;}
		ans+=r+1;
		l++;
	}
	return ans;
}
int check(ll x)
{
	for(auto &t:v)while(x%t==0)x/=t;
	for(auto &t:v1)while(x%t==0)x/=t;
	return x==1?1:0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){ll x;scanf("%lld",&x);if(i%2)v.pb(x);else v1.pb(x);}
	ll k;scanf("%lld",&k);
	dfs(1,0);dfs1(1,0);a.pb(1);b.pb(1);
	lena=(int)a.size();lenb=(int)b.size();
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll l=1,r=1e18;
	while(1)
	{
		ll mid=(l+r)/2;ll sum=fun(mid);//printf("----- %lld %lld %lld\n",l,r,sum );
		if(sum==k&&check(mid)){printf("%lld\n",mid);exit(0);}
		if(sum<k)l=mid+1;
		else r=mid-1;
	}
	return 0;
}
