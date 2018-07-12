ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){x=1LL;y=0;return a;}
    ll r=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return r;
}
// by+(a-a/b*b)x = ax+b(y-a/b*x)