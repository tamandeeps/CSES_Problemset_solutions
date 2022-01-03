#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
int main()
{
	int n, m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int dp[n+1][m+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==0 and j+1<=m)
			{
				dp[i][j]=dp[i-1][j]%mod +dp[i-1][j-1]%mod +dp[i-1][j+1]%mod;
			}
			else
				if(a[i-1]==0)
				{
					dp[i][j]=dp[i-1][j]%mod +dp[i-1][j-1]%mod;
				}
				if(a[i-1] !=0 and a[i-1]!=j)
				{
					dp[i][j]=0;
				}
				else
					if(a[i-1]==j)
					dp[i][j]=1;

		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		ans+=dp[n][i]%mod;
	cout<<ans;
	return 0;
}