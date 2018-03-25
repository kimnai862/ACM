/*
枚举n的因子，对每个因子y求出对应的gcd(n,x)=y=>gcd(n/y,x/y)=1,欧拉函数
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
#define ll __int64

int vis[maxn];
vector<int>v;
int oula(int x)
{
    if(x==1) return 1;
    vector<int>v1;
    int xx=x;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]*v[i]>xx) break;
        if(xx%v[i]) continue;
        while(!(xx%v[i]))
        {
            xx/=v[i];
        }
        v1.push_back(v[i]);
        if(xx==1) break;
    }
    if(xx!=1) v1.push_back(xx);
    int ans=x;
    for(int i=0;i<v1.size();i++)
        ans=ans/v1[i]*(v1[i]-1);
    return ans;
}

int main()
{
    memset(vis,1,sizeof(vis));
    for(int i=2;i<maxn;i++)
    {
        int j=2*i;
        while(j<maxn)
        {
            vis[j]=0;
            j+=i;
        }
    }
    for(int i=2;i<maxn;i++)
        if(vis[i])
        v.push_back(i);
  //  printf("%d\n",oula(3));
    int p;
    cin >> p;
    ll ans=0;
    for(int i=1;i*i<=p;i++)
    {
        if(p%i) continue;
        int m=p/i;
        ans+=(ll)oula(i)*(ll)m;
//        printf("%I64d\n",ans);
        if(m!=i)
            ans+=(ll)oula(m)*(ll)i;
 //       printf("%I64d\n",ans);
    }
    printf("%I64d\n",ans);
}