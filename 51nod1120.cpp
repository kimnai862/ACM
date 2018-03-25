/*
卡特兰数，c(x+y,x)-c(x+y,x+1)
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+5;
const int p = 10007;
int inv[N],fac[N]={1};
int modexp(int a,int b,int p)
{
    int ans=1;a%=p;
    while(b){if(b&1)ans=ans*a%p;a=a*a%p;b>>=1;}
    return ans;
}
int c(int a,int b){return (fac[a]*inv[a-b]%p)*inv[b]%p;}
int lucas(int a,int b,int p)
{
    if(b==0) return 1;
    return c(a%p,b%p)*lucas(a/p,b/p,p)%p;
}
int main()
{
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%p;
    for(int i=0;i<N;i++) inv[i]=modexp(fac[i],p-2,p);
    int n;scanf("%d",&n);
    printf("%d\n",(lucas(2*(n-1),n-1,p)-lucas(2*(n-1),n,p)+p)*2%p);
    return 0;
}