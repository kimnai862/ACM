#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
const int N = 1e6+5;
vector<int>pri;
int vis[N];
int main()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<N;i++){
        int j=2*i;if(vis[i])continue;
        while(j<N){vis[j]=1;j+=i;}
    }
    for(int i=2;i<N;i++)if(!vis[i])pri.pb(i);
    int n;scanf("%d",&n);
    ll ans=1LL;
    int n1=n;
    for(int i=0;pri[i]*pri[i]<=n1;i++){
        ll tmp=0,num=0;
        if(n1%pri[i]==0){
            tmp=1;num=0;
            while(n1%pri[i]==0){n1/=pri[i];tmp*=pri[i];num++;}
            tmp+=num*tmp/pri[i]*(pri[i]-1);
            ans*=tmp;
        }
    }if(n1!=1)ans*=(2*n1-1);
    printf("%lld\n",ans);
    return 0;
}