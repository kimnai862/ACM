/*
整数划分，不同数字，dp[i][j]表示和为i的用j个数字的方案数
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int maxn = 5e4+5;
const int mod = 1e9+7;

int dp[maxn][351]={0};

int main()
{
    int n;
    scanf("%d",&n);
    dp[0][0]=1;
    for(int j=1;j<=sqrt(2*n);j++){
        for(int i=j;i<=n;i++)
            dp[i][j]=(dp[i-j][j]+dp[i-j][j-1])%mod;
    }
    int ans=0;
    for(int i=1;i<=sqrt(2*n);i++)
        ans=(ans+dp[n][i])%mod;
    printf("%d\n",ans);
};