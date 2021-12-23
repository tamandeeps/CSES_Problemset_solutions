#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main()
{
	
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<vector<int>> dp(n,vector<int> (x+1,0));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			if(j==0 )
				dp[i][j]=1;
			if(i==1)
				dp[i][a[i]]=1;
			if(j-a[i-1]<0)
				continue;
			dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n-1][x];
	return 0;
}