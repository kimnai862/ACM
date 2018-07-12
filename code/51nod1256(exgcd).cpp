#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){x=1LL;y=0;return a;}
    ll r=exgcd(b,a%b,x,y);
    ll t=x;x=y;y=t-a/b*y;
    return r;
}
int main()
{
    ll a,b;scanf("%lld %lld",&a,&b);
    ll x,y;
    exgcd(a,b,x,y);
    if(y>0){
        ll tmp = y/a+1;
        x+=b*tmp;
    }else if(y<0&&x>0){
        ll tmp = x/b;
        x-=tmp*b;
    }
    printf("%lld\n",x);
    return 0;
}