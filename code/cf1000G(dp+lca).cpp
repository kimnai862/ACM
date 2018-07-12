#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long

const int N = 3e5+5;

ll w[N],sum[N][2];
vector<pair<int,ll> >g[N];
map<int,ll>m[N],ask[N];
int h[N],Next[N][22],Fa[N];
pair<int,ll>dp[N][22];
void dfs(int u,int fa)
{
    Fa[u]=fa;
    ll tmp = w[u];
    for(auto t:g[u]){
        if(t.fi==fa)continue;
        dfs(t.fi,u);
        if(sum[t.fi][0]>2*t.se){
            tmp+=sum[t.fi][0]-2*t.se;
        }
    }
    sum[u][0]=tmp;m[u][0]=tmp;
    for(auto t:g[u]){
        if(sum[t.fi][0]>2*t.se){
            m[u][t.fi]=tmp-(sum[t.fi][0]-2*t.se);
        }else{
            m[u][t.fi]=tmp;
        }
    }
}
void dfs1(int u,int fa,ll favalue)
{
    sum[u][1]=favalue;
    favalue+=sum[u][0];
    for(auto t:g[u]){
        if(t.fi==fa)continue;
        ll tmp=favalue;
        if(sum[t.fi][0]-2*t.se>0){
            tmp-=(sum[t.fi][0]-2*t.se);
        }
        dfs1(t.fi,u,max(tmp-2*t.se,0LL));
    }
}
void dfs2(int u,int fa,int deep)
{
    h[u]=deep;
    if(fa==-1){
        Next[u][0]=u;
    }
    for(int i=0;i<22;i++){
        if(fa==-1)continue;
        if(i==0){
            dp[u][i]={fa,sum[u][0]+m[fa][u]+sum[fa][1]-ask[u][fa]};
            Next[u][i]=u;
        }else{
            int id = dp[u][i-1].fi;
            if(id==-1)continue;
            int id1 = dp[id][i-1].fi;
            if(id1==-1)continue;
            dp[u][i]={id1,dp[u][i-1].se+dp[id][i-1].se-sum[id][0]-sum[id][1]};
            Next[u][i]=Next[id][i-1];
        }
    }
    for(auto t:g[u]){
        if(t.fi==fa)continue;
        dfs2(t.fi,u,deep+1);
    }
}
ll fun(int x,int y)
{
    if(x==y)return sum[x][0]+sum[x][1];
    ll ansx,ansy,ans=0;
    ansx=sum[x][0]+sum[x][1];
    ansy=sum[y][0]+sum[y][1];
    int xx=0,yy=0;
    while(true)
    {
 //       printf("--------- %d %d %d %d\n",x,y,h[x],h[y]);
        if(h[x]>h[y]){
            int i;
            for(i=21;i>=0;i--){
                if(dp[x][i].fi==-1)continue;
                int id = dp[x][i].fi;
                if(h[y]<=h[id])break;
            }
            ansx=ansx+dp[x][i].se-sum[x][1]-sum[x][0];
            xx=Next[x][i];
            x=dp[x][i].fi;
        }else if(h[x]<h[y]){
            int i;
            for(i=21;i>=0;i--){
                if(dp[y][i].fi==-1)continue;
                int id = dp[y][i].fi;
                if(h[x]<=h[id])break;
            }
            ansy=ansy+dp[y][i].se-sum[y][1]-sum[y][0];
            yy=Next[y][i];
  //          printf("----- %d %d\n",i,yy);
            y=dp[y][i].fi;
        }else{
            if(x==y){
                ans=ansx+ansy;
   //             printf("-- %lld %d %d %d %lld %lld\n",ans,x,xx,yy,ansx,ansy);
                ans-=m[x][xx]+sum[x][1];
                ans-=m[y][yy]+sum[y][1];
   //             printf("---- %lld\n",ans);
                ans+=sum[x][1];
                ans+=w[x];
                for(auto t:g[x]){
                    if(t.fi==Fa[x]||t.fi==xx||t.fi==yy)continue;
                    if(sum[t.fi][0]>2*t.se){
                        ans+=sum[t.fi][0]-2*t.se;
                    }
                }
                break;
            }else{
                int i;
                for(i=21;i>=0;i--){
                    if(dp[x][i].fi==-1)continue;
                    if(Next[x][i]!=Next[y][i])
                        break;
                }
                ansx=ansx+dp[x][i].se-sum[x][1]-sum[x][0];
                ansy=ansy+dp[y][i].se-sum[y][1]-sum[y][0];
                xx=Next[x][i];
                yy=Next[y][i];
                x=dp[x][i].fi;
                y=dp[y][i].fi;
            }
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
  //  freopen("in.txt","r",stdin);
    memset(sum,0,sizeof(sum));
    memset(w,0,sizeof(w));
    memset(h,0,sizeof(h));
    memset(Next,-1,sizeof(Next));
    memset(Fa,-1,sizeof(Fa));
    int n,q;scanf("%d%d",&n,&q);
    for(int i=0;i<=n;i++)for(int j=0;j<22;j++)dp[i][j]={-1,-1};
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    for(int i=1;i<n;i++){
        int u,v;ll cost;
        scanf("%d%d%lld",&u,&v,&cost);
        ask[u][v]=cost;ask[v][u]=cost;
        g[u].pb({v,cost});
        g[v].pb({u,cost});
    }
    dfs(1,-1);
    dfs1(1,-1,0);
    dfs2(1,-1,0);
    /*for(int i=1;i<=n;i++){
        printf("-- %d %lld %lld %d %lld\n",i,sum[i][0],sum[i][1],dp[i][0].fi,dp[i][0].se);
    }*/
    for(int i=1;i<=q;i++){
        int l,r;scanf("%d %d",&l,&r);
        printf("%lld\n",fun(l,r));
    }
    return 0;
}