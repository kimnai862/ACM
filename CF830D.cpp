/*
dp[i][j]表示深度为i的满二叉树中存在j条不想交简单路径的方案数
*/
#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 1e6+5;
const ll p = 1e9+7;
ll dp[505][505];
int main()
{
	memset(dp,0,sizeof(dp));
	int kk;scanf("%d",&kk);
	dp[1][0]=dp[1][1]=1LL;
	for(int i=2;i<=kk;i++){
		for(int j=0;j<=kk;j++){
			for(int k=0;k+j<=kk;k++){ll tmp=dp[i-1][j]*dp[i-1][k]%p;
				dp[i][j+k]=(dp[i][j+k]+tmp)%p;
				dp[i][j+k]=(dp[i][j+k]+tmp*(j+k)*2LL)%p;
				dp[i][j+k-1]=(dp[i][j+k-1]+tmp*(j+k)*(j+k-1LL))%p;
				dp[i][j+k+1]=(dp[i][j+k+1]+tmp)%p;
			}
		}
	}printf("%lld\n",dp[kk][1]);
	return 0;
}