#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
int a[N];
int main(int argc, char const *argv[])
{
    memset(a,0,sizeof(a));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        for(int j=1;j*j<=x;j++){
            if(x%j==0){
                a[j]++;
                if(j*j!=x) a[x/j]++;
            }
        }
    }
    int ans=0;
    for(int i=1e6;i>=2;i--) if(a[i]>=2){ans=i;break;}
    printf("%d\n",ans);
    return 0;
}