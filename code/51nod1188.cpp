#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
const int N = 5e6+5;
ll phi[N],len;
vector<int>pri;
void initPhi()
{
    memset(phi,0,sizeof(phi));
    len=0;phi[1]=1;
    for(int i=2;i<N;i++){
        if(!phi[i]){
            phi[i]=i-1;
            pri.pb(i);
            len++;
        }
        for(int j=0;j<len&&pri[j]*i<N;j++){
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
}
ll ans[N];
namespace IO{
    const int maxn = 10*1024*1024;
    char s[maxn];
    int p,sz;
    void begin(){
        p = 0;
        sz = fread(s,1,maxn,stdin);
    }
    template<typename T>
    inline bool scand(T &t){
        while(p<sz&&s[p]!='-'&&(s[p]<'0'||s[p]>'9'))p++;
        if(p>=sz) return false;
        bool sgn=false;
        if(s[p]=='-') sgn=true,p++;
        for(t=0;p<sz&&'0'<=s[p]&&s[p]<='9';p++)
            t=t*10+s[p]-'0';
        if(sgn) t=-t;
        return true;
    }
    template<typename T>
    void print(T x){
        static char s[65],*s1;s1=s;
        if(!x) *s1++='0';
        if(x<0)putchar('-'),x=-x;
        while(x)*s1++ = (x%10+'0'),x/=10;
        while(s1--!=s)putchar(*s1);
    }
    template<typename T>
    void println(T x){
        print(x);putchar('\n');
    }
}
using namespace IO;
int main()
{
    begin();
    initPhi();
    memset(ans,0,sizeof(ans));
    for(int i=1;i<N;i++)for(int j=2;j*i<N;j++)ans[i*j]+=1LL*i*phi[j];
    for(int i=2;i<N;i++)ans[i]+=ans[i-1];
    int t;scand(t);
    while(t--)
    {
        int x;scand(x);
        println(ans[x]);
    }
    return 0;
}