#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

const int N = 1e6+5;
int vis[N];
vector<ll>pri;
ll modexp(ll a,ll b,ll p)
{
    ll ans=1LL;a%=p;
    while(b){if(b&1)ans=ans*a%p;b>>=1;a=a*a%p;}
    return ans;
}
int main()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<N;i++){
        if(vis[i]) continue;
        int j = 2*i;
        while(j<N){vis[j]=1;j+=i;}
    }
    for(int i=2;i<N;i++)if(!vis[i]) pri.pb(i);
    ll a,b,b1;scanf("%lld %lld",&a,&b);b1=b;
    ll ans = b;
    for(int i=0;pri[i]*pri[i]<=b;i++){
        ll p = pri[i];
        if(b%p==0){
            ans-=ans/p;
            while(b%p==0){b/=p;}
        }
    }if(b!=1){
        ans-=ans/b;
    }
    printf("%lld\n",modexp(a,ans-1,b1));
    return 0;
}