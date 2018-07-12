ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){x=1LL;y=0;return a;}
    ll r=exgcd(b,a%b,x,y);
    ll t=x;x=y;y=t-a/b*y;
    return r;
}