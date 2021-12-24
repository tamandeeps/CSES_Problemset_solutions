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
	dp[0][a[0]]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			if(j==0 )
			{
				dp[i][j]=1;
				continue;
			}
			int option1=0,option2=0;
			if(j-a[i]>=0)
				option1=dp[i][j-a[i]];
			if(i==0 and j%a[i]==0)
				option2=1;
            dp[i][j]=option2+option1;
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n-1][x];
	return 0;
}