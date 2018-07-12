#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
const int N = 1e6+5;

int vis[N];
vector<int>P;
ll modexp(ll a,ll b,ll p)
{
    ll ans=1LL;a%=p;
    while(b){if(b&1)ans=ans*a%p;a=a*a%p;b>>=1;}
    return ans;
}
int main()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<N;i++){
        if(vis[i])continue;
        int j = 2*i;
        while(j<N){vis[j]=1;j+=i;}
    }
    for(int i=2;i<N;i++)if(!vis[i])P.pb(i);
    int p;scanf("%d",&p);
    int pp = p;
    p-=1;
    vector<int>tmp;
    for(int i=0;P[i]*P[i]<=p;i++){
        if(p%P[i]==0){
            tmp.pb(P[i]);
            while(p%P[i]==0){p/=P[i];}
        }
    }
    if(p!=1)tmp.pb(p);
    int ans=-1;
    for(int i=2;;i++){
        int flag=1;
        for(int j=0;j<(int)tmp.size();j++){
            int t=modexp(i,(pp-1)/tmp[j],pp);
            if(t==1)
                flag=0;
        }
        if(flag){ans=i;break;}
    }printf("%d\n",ans);
    return 0;
}