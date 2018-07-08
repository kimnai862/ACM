void tarjan(int u,int fa)
{

    dfn[u]=low[u]=++id;st[++st_id]=u;
    vis[u]=1;
    for(auto &t:g[u]){
        if(t==fa)continue;
        if(!vis[t])tarjan(t,u);
        low[u]=min(low[u],low[t]); 
    }
    if(low[u]==dfn[u]){
        tot++;
        while(low[st[st_id]]>=low[u]){
            has[st[st_id--]]=tot;//缩点
        }
    }
}