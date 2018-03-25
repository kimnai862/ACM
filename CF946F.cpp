/*
dp[i][l][r]表示在第i个字符串中子串l~r的个数
/*
#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
const int N = 1e6+5;
const ll INF = 1e18;
const ll p = 1e9+7;

ll len[105],dp[105][105][105];
int main()
{
	memset(dp,0,sizeof(dp));
	len[0]=len[1]=2;for(int i=2;i<105;i++)len[i]=(len[i-1]*len[i-2])%p;
	int n,x;scanf("%d%d",&n,&x);
	string s;cin >> s;
	for(int i=0;i<(int)s.size();i++)dp[s[i]-'0'][i+1][i+1]=1;
	for(int i=2;i<=x;i++){
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if(r!=n) dp[i][l][r]+=dp[i-1][l][r];
				else dp[i][l][r]+=dp[i-1][l][r]*len[i-2]%p;
				dp[i][l][r]%=p;
				if(l!=1) dp[i][l][r]+=dp[i-2][l][r];
				else dp[i][l][r]+=dp[i-2][l][r]*len[i-1]%p;
				dp[i][l][r]%=p;
				for(int k=l+1;k<=r;k++){
					dp[i][l][r]+=dp[i-1][l][k-1]*dp[i-2][k][r]%p;
					dp[i][l][r]%=p;	
				}
			}
		}
		
	}printf("%lld\n",dp[x][1][n]);
	return 0;
}